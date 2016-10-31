/*
 *                               POK header
 * 
 * The following file is a part of the POK project. Any modification should
 * made according to the POK licence. You CANNOT use this file or a part of
 * this file is this part of a file for your own project
 *
 * For more information on the POK licence, please see our LICENCE FILE
 *
 * Please follow the coding guidelines described in doc/CODING_GUIDELINES
 *
 *                                      Copyright (c) 2007-2009 POK team 
 *
 * Created by julien on Thu Jan 15 23:34:13 2009 
 */

/**
 * \file loader.c
 * \author Julian Pidancet
 * \author Julien Delange
 * \date 2008-2009
 *
 * Contains all needed stuff to load partitions (elf files).
 * This needs the partitioning service (POK_NEEDS_PARTITIONS must
 * be defined) to work.
 */

#include <config.h>

#ifdef POK_NEEDS_PARTITIONS

#include <errno.h>
#include <types.h>
#include <libc.h>
#include <core/cpio.h>
#include <core/error.h>
#include <core/partition.h>
#include <core/debug.h>
#include <elf.h>

#include <core/space.h>

extern size_t pok_elf_sizes[];
extern char __archive2_begin;

/**
 * Load an ELF file.
 *
 *  @param file
 */
pok_ret_t jet_loader_elf_load   (uint8_t elf_id,
                                 jet_space_id space_id,
                                 void (** entry)(void))
{
    size_t elf_offset, elf_size;

    struct jet_space_layout space_layout;
    ja_space_layout_get(space_id, &space_layout);

    elf_offset = 0;
    for (uint8_t i = 0; i < elf_id; i++) {
        elf_offset += pok_elf_sizes[i];
    }

    elf_size = pok_elf_sizes[elf_id];

    if (elf_size > space_layout.size)
    {
         printf("Attempt to load elf %u of size %zx into space of size %zx.\n",
            elf_id, elf_size, space_layout.size);
//TODO: How to emit partition's error?
//#ifdef POK_NEEDS_ERROR_HANDLING
//        pok_error_raise_partition(part_id, POK_ERROR_KIND_PARTITION_CONFIGURATION);
//#else
#ifdef POK_NEEDS_DEBUG
      /* We consider that even if errors are not raised, we must print an error
       * for such error
       * So, when we are using the debug mode, we print a fatal error.
       */
        pok_fatal ("Partition size is not correct\n");
#endif
//#endif
    }

    const char* elf_start = &__archive2_begin + elf_offset;


    Elf32_Ehdr*  elf_header;
    Elf32_Phdr*  elf_phdr;

    elf_header = (Elf32_Ehdr*)elf_start;

    if (elf_header->e_ident[0] != 0x7f ||
         elf_header->e_ident[1] != 'E' ||
         elf_header->e_ident[2] != 'L' ||
         elf_header->e_ident[3] != 'F')
    {
        return POK_ERRNO_NOTFOUND;
    }

    *entry = (void (*)(void)) elf_header->e_entry;

    elf_phdr = (Elf32_Phdr*)(elf_start + elf_header->e_phoff);

    for (int i = 0; i < elf_header->e_phnum; ++i)
    {
        char* user_dest = (char *)elf_phdr[i].p_vaddr;
        size_t filesz = elf_phdr[i].p_filesz;
        size_t memsz = elf_phdr[i].p_memsz;

        assert((user_dest >= space_layout.user_addr)
               && (user_dest + filesz < space_layout.user_addr + space_layout.size)
               && (user_dest + memsz < space_layout.user_addr + space_layout.size));

        char* kernel_dest = space_layout.kernel_addr + (user_dest - space_layout.user_addr);

        memcpy (kernel_dest, elf_phdr[i].p_offset + elf_start, filesz);
        memset (kernel_dest + filesz, 0, memsz - filesz);
    }

    return POK_ERRNO_OK;
}

#endif /* POK_NEEDS_PARTITIONS */
