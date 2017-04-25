/*
 * Institute for System Programming of the Russian Academy of Sciences
 * Copyright (C) 2016 ISPRAS
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation, Version 3.
 *
 * This program is distributed in the hope # that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
 *
 * See the GNU General Public License version 3 for more details.
 *
 * This file also incorporates the following work:
 * Copyright IBM Corp. 2009
 * Author(s): Peter Oberparleiter <oberpar@linux.vnet.ibm.com>
 */

#ifdef POK_NEEDS_GCOV

#include <alloc.h>
#include <libc.h>
#include <gcov.h>
#include <core/partition_arinc.h>
#include <core/uaccess.h>

/**
 * store_gcov_u32 - store 32 bit number in gcov format to buffer
 * @buffer: target buffer or NULL
 * @off: offset into the buffer
 * @v: value to be stored
 *
 * Number format defined by gcc: numbers are recorded in the 32 bit
 * unsigned binary form of the endianness of the machine generating the
 * file. Returns the number of bytes stored. If @buffer is %NULL, doesn't
 * store anything.
 */
static size_t store_gcov_u32(void *buffer, size_t off, uint32_t v)
{
    uint32_t *data;

    if (buffer) {
        data = (uint32_t*)((uint32_t)buffer + off);
        *data = v;
    }

    return sizeof(*data);
}

/**
 * store_gcov_u64 - store 64 bit number in gcov format to buffer
 * @buffer: target buffer or NULL
 * @off: offset into the buffer
 * @v: value to be stored
 *
 * Number format defined by gcc: numbers are recorded in the 32 bit
 * unsigned binary form of the endianness of the machine generating the
 * file. 64 bit numbers are stored as two 32 bit numbers, the low part
 * first. Returns the number of bytes stored. If @buffer is %NULL, doesn't store
 * anything.
 */
static size_t store_gcov_u64(void *buffer, size_t off, uint64_t v)
{
    uint32_t *data;

    if (buffer) {
        data = (uint32_t*)((uint32_t)buffer + off);

        data[0] = (v & 0xffffffffUL);
        data[1] = (v >> 32);
    }

    return sizeof(*data) * 2;
}

/*
 * Determine whether a counter is active. Doesn't change at run-time.
 */
static int counter_active(struct gcov_info *info, unsigned int type)
{
    return info->merge[type] ? 1 : 0;
}

/**
 * convert_to_gcda - convert profiling data set to gcda file format
 * @buffer: the buffer to store file data or %NULL if no data should be stored
 * @info: profiling data set to be converted
 *
 * Returns the number of bytes that were/would have been stored into the buffer.
 */
static size_t convert_to_gcda(unsigned char *buffer, struct gcov_info *info)
{
    struct gcov_fn_info *fi_ptr;
    struct gcov_ctr_info *ci_ptr;
    unsigned int fi_idx;
    unsigned int ct_idx;
    unsigned int cv_idx;
    size_t pos = 0;

    /* File header. */
    pos += store_gcov_u32(buffer, pos, GCOV_DATA_MAGIC);
    pos += store_gcov_u32(buffer, pos, info->version);
    pos += store_gcov_u32(buffer, pos, info->stamp);

    for (fi_idx = 0; fi_idx < info->n_functions; fi_idx++) {
        fi_ptr = info->functions[fi_idx];

        /* Function record. */
        pos += store_gcov_u32(buffer, pos, GCOV_TAG_FUNCTION);
        pos += store_gcov_u32(buffer, pos, GCOV_TAG_FUNCTION_LENGTH);
        pos += store_gcov_u32(buffer, pos, fi_ptr->ident);
        pos += store_gcov_u32(buffer, pos, fi_ptr->lineno_checksum);
        pos += store_gcov_u32(buffer, pos, fi_ptr->cfg_checksum);

        ci_ptr = fi_ptr->ctrs;

        for (ct_idx = 0; ct_idx < GCOV_COUNTERS; ct_idx++) {
            if (!counter_active(info, ct_idx))
                continue;

            /* Counter record. */
            pos += store_gcov_u32(buffer, pos,
                          GCOV_TAG_FOR_COUNTER(ct_idx));
            pos += store_gcov_u32(buffer, pos, ci_ptr->num * 2);

            for (cv_idx = 0; cv_idx < ci_ptr->num; cv_idx++) {
                pos += store_gcov_u64(buffer, pos,
                              ci_ptr->values[cv_idx]);
            }

            ci_ptr++;
        }
    }

    return pos;
}

static size_t dump_gcov_entry(unsigned char *to_buffer, struct gcov_info *info)
{
    if (info == NULL) {
        return 0;
    }

    size_t sz = convert_to_gcda(NULL, info);
    if (sz >= GCOV_HEXDUMP_BUF_SIZE) {
        printf("%s: size for '%s' is %zd, limit %d\n",
                __func__, info->filename, sz,
                GCOV_HEXDUMP_BUF_SIZE);
        return sz;
    }

    sz = convert_to_gcda(to_buffer, info);
    return sz;
}

static unsigned char *data;

static struct gcov_entry_t *entry;

static struct gcov_info **gcov_info_head;

static size_t total_size = 0;
static size_t num_entries_kernel = 0;
static size_t num_entries_partitions = 0;

void fill_entry(struct gcov_info *info, size_t offset)
{
    memcpy(entry[offset].filename, info->filename, strlen(info->filename) + 1);

    // offset in common buffer
    entry[offset].data_start = (uint32_t)data + total_size;

    size_t sz = dump_gcov_entry(data + total_size, info);
    total_size += sz;
    entry[offset].data_end = entry[offset].data_start + sz;
}

void dump_kernel(void)
{
    for (size_t i = 0; i < num_entries_kernel; i++) {
        fill_entry(gcov_info_head[i], i);
    }
}

void dump_partition(pok_partition_arinc_t *part)
{
    pok_space_switch(part->base_part.space_id);
    struct gcov_info **info_head = part->gcov_part_data->gcov_info_head;
    size_t num_entries = part->gcov_part_data->num_used_gcov_entries;

    if (info_head == NULL) {
        printf("kernel: %s: NULL info_head\n", __func__);
        return;
    }

    for (size_t i = 0; i < num_entries; i++) {
        fill_entry(jet_user_to_kernel(info_head[i], sizeof(struct gcov_info*)),
            i + num_entries_kernel + num_entries_partitions);
    }
    num_entries_partitions += num_entries;
}

void gcov_dump(void)
{
    dump_kernel();
    for(uint8_t i = 0; i < pok_partitions_arinc_n; i++) {
        dump_partition(&pok_partitions_arinc[i]);
    }
    printf("total entries: %zu\n", num_entries_kernel + num_entries_partitions);
    printf("total size:    %zu\n", total_size);
}

/*
* __gcov_init is called by gcc-generated constructor code for each object
* file compiled with -fprofile-arcs.
*/
void __gcov_init(struct gcov_info *info)
{
    if (info == NULL) {
        printf("kernel: %s: NULL info\n", __func__);
        return;
    }

    if (num_entries_kernel >= DEFAULT_GCOV_ENTRY_COUNT) {
        printf("kernel: %s: gcov_info_head is full, all %zd entries used\n",
                __func__, num_entries_kernel);
        return;
    }

    gcov_info_head[num_entries_kernel++] = info;
}

/* Call the coverage initializers if not done by startup code */
void pok_gcov_init(void) {
    data = ja_mem_alloc_aligned(
        GCOV_MAX_DATA_SIZE * sizeof(unsigned char),
        __alignof__(unsigned char));

    entry = ja_mem_alloc_aligned(
        DEFAULT_GCOV_ENTRY_COUNT * sizeof(struct gcov_entry_t),
        __alignof__(struct gcov_entry_t));

    for (size_t i = 0; i < DEFAULT_GCOV_ENTRY_COUNT; i++) {
        entry[i].filename = ja_mem_alloc_aligned(
            GCOV_MAX_FILENAME_LENGTH * sizeof(char),
            __alignof__(char));
    }

    gcov_info_head = ja_mem_alloc_aligned(
        DEFAULT_GCOV_ENTRY_COUNT * sizeof(struct gcov_info*),
        __alignof__(struct gcov_info*));

    extern uint32_t __CTOR_START__, __CTOR_END__; // linker defined symbols
    uint32_t start = (uint32_t)(&__CTOR_START__ + 1);
    uint32_t end = (uint32_t)(&__CTOR_END__ - 1);
    printf("start 0x%lx, end 0x%lx\n", start, end);
    void (**p)(void);

    while(start < end) {
        p = (void(**)(void))start; // get function pointer
        (*p)(); // call constructor
        start += sizeof(p);
    }
}

#endif /* POK_NEEDS_GCOV */
