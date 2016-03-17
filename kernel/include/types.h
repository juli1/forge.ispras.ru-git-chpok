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


#ifndef __POK_TYPES_H__
#define __POK_TYPES_H__

#include <stdint.h>
#include <stddef.h>
#include <libc.h>

#define FALSE  0
#define TRUE   1
typedef int bool_t;
typedef int pok_bool_t;

typedef uint32_t pok_port_size_t;
typedef uint8_t pok_port_direction_t;
typedef uint8_t pok_port_kind_t;
typedef uint8_t pok_port_id_t;
typedef uint8_t pok_size_t;
typedef uint8_t pok_range_t; // Range of messages is different.
typedef uint8_t pok_buffer_id_t;
typedef uint8_t pok_blackboard_id_t;
typedef uint16_t pok_lockobj_id_t;
typedef uint16_t pok_sem_id_t;
typedef uint16_t pok_event_id_t;
typedef uint8_t pok_partition_id_t;
typedef uint8_t pok_thread_id_t;
typedef enum {
    POK_BLACKBOARD_EMPTY,
    POK_BLACKBOARD_OCCUPIED
} pok_blackboard_empty_t;
typedef uint16_t pok_sem_value_t;
typedef enum {
    POK_EVENT_UP,
    POK_EVENT_DOWN
} pok_event_state_t;

typedef uint16_t pok_message_size_t; // 0....8192
typedef uint16_t pok_message_range_t; // 0...512

typedef int64_t pok_time_t;

/* This constant should be used for *set* time as infinity(special). */
#define POK_TIME_INFINITY ((int64_t)(-1))

/* 
 * This function should be used for check (untrusted) time whether
 * it is infinity(special) or not.
 */
static inline pok_bool_t pok_time_is_infinity(pok_time_t t)
{
    return (t<0);
}

typedef enum {
    POK_QUEUEING_DISCIPLINE_FIFO,
    POK_QUEUEING_DISCIPLINE_PRIORITY,
} pok_queuing_discipline_t;

#define MAX_NAME_LENGTH 30

/* 
 * Compare names.
 * 
 * Name is a array of bytes, which is either of MAX_NAME_LENGTH size
 * without null-bytes, or have null-byte in the first MAX_NAME_LENGTH
 * bytes.
 */
int   strncmp(const char *s1, const char *s2, size_t size);
static inline int pok_compare_names(const char* name1, const char* name2)
{
    return strncmp(name1, name2, MAX_NAME_LENGTH);
}

#endif
