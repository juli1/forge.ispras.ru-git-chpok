/*
 * GENERATED! DO NOT MODIFY!
 *
 * Instead of modifying this file, modify the one it generated from (kernel/include/uapi/syscall_map_arinc.h.in).
 */
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
 */


#include <uapi/types.h>
#include <uapi/thread_types.h>
#include <uapi/partition_types.h>
#include <uapi/partition_arinc_types.h>
#include <uapi/port_types.h>
#include <uapi/buffer_types.h>
#include <uapi/blackboard_types.h>
#include <uapi/semaphore_types.h>
#include <uapi/event_types.h>
#include <uapi/error_arinc_types.h>

pok_ret_t pok_thread_create(const char* __user name,
    void* __user entry,
    const pok_thread_attr_t* __user attr,
    pok_thread_id_t* __user thread_id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_CREATE(const pok_syscall_args_t* args)
{
    return pok_thread_create(
        (const char* __user)args->arg1,
        (void* __user)args->arg2,
        (const pok_thread_attr_t* __user)args->arg3,
        (pok_thread_id_t* __user)args->arg4);
}

#ifdef POK_NEEDS_THREAD_SLEEP
pok_ret_t pok_thread_sleep(const pok_time_t* __user time);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_SLEEP(const pok_syscall_args_t* args)
{
    return pok_thread_sleep(
        (const pok_time_t* __user)args->arg1);
}
#endif

#ifdef POK_NEEDS_THREAD_SLEEP_UNTIL
pok_ret_t pok_thread_sleep_until(const pok_time_t* __user time);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_SLEEP_UNTIL(const pok_syscall_args_t* args)
{
    return pok_thread_sleep_until(
        (const pok_time_t* __user)args->arg1);
}
#endif
pok_ret_t pok_sched_end_period(void);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_PERIOD(const pok_syscall_args_t* args)
{
    return pok_sched_end_period();
}

#if defined (POK_NEEDS_THREAD_SUSPEND) || defined (POK_NEEDS_ERROR_HANDLING)
pok_ret_t pok_thread_suspend(const pok_time_t* __user time);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_SUSPEND(const pok_syscall_args_t* args)
{
    return pok_thread_suspend(
        (const pok_time_t* __user)args->arg1);
}
#endif

#ifdef POK_NEEDS_THREAD_ID
pok_ret_t pok_sched_get_current(pok_thread_id_t* __user thread_id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_ID(const pok_syscall_args_t* args)
{
    return pok_sched_get_current(
        (pok_thread_id_t* __user)args->arg1);
}
#endif
pok_ret_t pok_thread_get_status(pok_thread_id_t thread_id,
    char* __user name,
    void** __user entry,
    pok_thread_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_STATUS(const pok_syscall_args_t* args)
{
    return pok_thread_get_status(
        (pok_thread_id_t)args->arg1,
        (char* __user)args->arg2,
        (void** __user)args->arg3,
        (pok_thread_status_t* __user)args->arg4);
}

pok_ret_t pok_thread_delayed_start(pok_thread_id_t thread_id,
    const pok_time_t* __user time);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_DELAYED_START(const pok_syscall_args_t* args)
{
    return pok_thread_delayed_start(
        (pok_thread_id_t)args->arg1,
        (const pok_time_t* __user)args->arg2);
}

pok_ret_t pok_thread_set_priority(pok_thread_id_t thread_id,
    uint32_t priority);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_SET_PRIORITY(const pok_syscall_args_t* args)
{
    return pok_thread_set_priority(
        (pok_thread_id_t)args->arg1,
        (uint32_t)args->arg2);
}

pok_ret_t pok_thread_resume(pok_thread_id_t thread_id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_RESUME(const pok_syscall_args_t* args)
{
    return pok_thread_resume(
        (pok_thread_id_t)args->arg1);
}

pok_ret_t pok_thread_suspend_target(pok_thread_id_t thread_id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_SUSPEND_TARGET(const pok_syscall_args_t* args)
{
    return pok_thread_suspend_target(
        (pok_thread_id_t)args->arg1);
}

pok_ret_t pok_thread_yield(void);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_YIELD(const pok_syscall_args_t* args)
{
    return pok_thread_yield();
}

pok_ret_t pok_sched_replenish(const pok_time_t* __user budget);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_REPLENISH(const pok_syscall_args_t* args)
{
    return pok_sched_replenish(
        (const pok_time_t* __user)args->arg1);
}

pok_ret_t pok_thread_stop_target(pok_thread_id_t thread_id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_STOP(const pok_syscall_args_t* args)
{
    return pok_thread_stop_target(
        (pok_thread_id_t)args->arg1);
}

pok_ret_t pok_thread_stop(void);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_STOPSELF(const pok_syscall_args_t* args)
{
    return pok_thread_stop();
}

pok_ret_t pok_thread_find(const char* __user name,
    pok_thread_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_THREAD_FIND(const pok_syscall_args_t* args)
{
    return pok_thread_find(
        (const char* __user)args->arg1,
        (pok_thread_id_t* __user)args->arg2);
}

#ifdef POK_NEEDS_PARTITIONS
pok_ret_t pok_partition_set_mode_current(pok_partition_mode_t mode);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_PARTITION_SET_MODE(const pok_syscall_args_t* args)
{
    return pok_partition_set_mode_current(
        (pok_partition_mode_t)args->arg1);
}

pok_ret_t pok_current_partition_get_status(pok_partition_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_PARTITION_GET_STATUS(const pok_syscall_args_t* args)
{
    return pok_current_partition_get_status(
        (pok_partition_status_t* __user)args->arg1);
}

pok_ret_t pok_current_partition_inc_lock_level(int32_t* __user lock_level);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_PARTITION_INC_LOCK_LEVEL(const pok_syscall_args_t* args)
{
    return pok_current_partition_inc_lock_level(
        (int32_t* __user)args->arg1);
}

pok_ret_t pok_current_partition_dec_lock_level(int32_t* __user lock_level);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_PARTITION_DEC_LOCK_LEVEL(const pok_syscall_args_t* args)
{
    return pok_current_partition_dec_lock_level(
        (int32_t* __user)args->arg1);
}
#endif

#ifdef POK_NEEDS_BUFFERS
pok_ret_t pok_buffer_create(char* __user name,
    pok_message_size_t max_message_size,
    pok_message_range_t max_nb_message,
    pok_queuing_discipline_t discipline,
    pok_buffer_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BUFFER_CREATE(const pok_syscall_args_t* args)
{
    return pok_buffer_create(
        (char* __user)args->arg1,
        (pok_message_size_t)args->arg2,
        (pok_message_range_t)args->arg3,
        (pok_queuing_discipline_t)args->arg4,
        (pok_buffer_id_t* __user)args->arg5);
}

pok_ret_t pok_buffer_send(pok_buffer_id_t id,
    const void* __user data,
    pok_message_size_t length,
    const pok_time_t* __user timeout);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BUFFER_SEND(const pok_syscall_args_t* args)
{
    return pok_buffer_send(
        (pok_buffer_id_t)args->arg1,
        (const void* __user)args->arg2,
        (pok_message_size_t)args->arg3,
        (const pok_time_t* __user)args->arg4);
}
   
pok_ret_t pok_buffer_receive(pok_buffer_id_t id,
    const pok_time_t* __user timeout,
    void* __user data,
    pok_message_size_t* __user length);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BUFFER_RECEIVE(const pok_syscall_args_t* args)
{
    return pok_buffer_receive(
        (pok_buffer_id_t)args->arg1,
        (const pok_time_t* __user)args->arg2,
        (void* __user)args->arg3,
        (pok_message_size_t* __user)args->arg4);
}

pok_ret_t pok_buffer_get_id(char* __user name,
    pok_buffer_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BUFFER_ID(const pok_syscall_args_t* args)
{
    return pok_buffer_get_id(
        (char* __user)args->arg1,
        (pok_buffer_id_t* __user)args->arg2);
}
                        
pok_ret_t pok_buffer_status(pok_buffer_id_t id,
    pok_buffer_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BUFFER_STATUS(const pok_syscall_args_t* args)
{
    return pok_buffer_status(
        (pok_buffer_id_t)args->arg1,
        (pok_buffer_status_t* __user)args->arg2);
}
#endif

#ifdef POK_NEEDS_BLACKBOARDS
pok_ret_t pok_blackboard_create(const char* __user name,
    pok_message_size_t max_message_size,
    pok_blackboard_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BLACKBOARD_CREATE(const pok_syscall_args_t* args)
{
    return pok_blackboard_create(
        (const char* __user)args->arg1,
        (pok_message_size_t)args->arg2,
        (pok_blackboard_id_t* __user)args->arg3);
}

pok_ret_t pok_blackboard_read(pok_blackboard_id_t id,
    const pok_time_t* __user timeout,
    void* __user data,
    pok_message_size_t* __user len);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BLACKBOARD_READ(const pok_syscall_args_t* args)
{
    return pok_blackboard_read(
        (pok_blackboard_id_t)args->arg1,
        (const pok_time_t* __user)args->arg2,
        (void* __user)args->arg3,
        (pok_message_size_t* __user)args->arg4);
}
   
pok_ret_t pok_blackboard_display(pok_blackboard_id_t id,
    const void* __user message,
    pok_message_size_t len);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BLACKBOARD_DISPLAY(const pok_syscall_args_t* args)
{
    return pok_blackboard_display(
        (pok_blackboard_id_t)args->arg1,
        (const void* __user)args->arg2,
        (pok_message_size_t)args->arg3);
}
   
pok_ret_t pok_blackboard_clear(pok_blackboard_id_t id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BLACKBOARD_CLEAR(const pok_syscall_args_t* args)
{
    return pok_blackboard_clear(
        (pok_blackboard_id_t)args->arg1);
}

pok_ret_t pok_blackboard_id(const char* __user name,
    pok_blackboard_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BLACKBOARD_ID(const pok_syscall_args_t* args)
{
    return pok_blackboard_id(
        (const char* __user)args->arg1,
        (pok_blackboard_id_t* __user)args->arg2);
}

pok_ret_t pok_blackboard_status(pok_blackboard_id_t id,
    pok_blackboard_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_BLACKBOARD_STATUS(const pok_syscall_args_t* args)
{
    return pok_blackboard_status(
        (pok_blackboard_id_t)args->arg1,
        (pok_blackboard_status_t* __user)args->arg2);
}
#endif

#ifdef POK_NEEDS_SEMAPHORES
pok_ret_t pok_semaphore_create(const char* __user name,
    pok_sem_value_t value,
    pok_sem_value_t max_value,
    pok_queuing_discipline_t discipline,
    pok_sem_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_SEMAPHORE_CREATE(const pok_syscall_args_t* args)
{
    return pok_semaphore_create(
        (const char* __user)args->arg1,
        (pok_sem_value_t)args->arg2,
        (pok_sem_value_t)args->arg3,
        (pok_queuing_discipline_t)args->arg4,
        (pok_sem_id_t* __user)args->arg5);
}

pok_ret_t pok_semaphore_wait(pok_sem_id_t id,
    const pok_time_t* __user timeout);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_SEMAPHORE_WAIT(const pok_syscall_args_t* args)
{
    return pok_semaphore_wait(
        (pok_sem_id_t)args->arg1,
        (const pok_time_t* __user)args->arg2);
}

pok_ret_t pok_semaphore_signal(pok_sem_id_t id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_SEMAPHORE_SIGNAL(const pok_syscall_args_t* args)
{
    return pok_semaphore_signal(
        (pok_sem_id_t)args->arg1);
}

pok_ret_t pok_semaphore_id(const char* __user name,
    pok_sem_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_SEMAPHORE_ID(const pok_syscall_args_t* args)
{
    return pok_semaphore_id(
        (const char* __user)args->arg1,
        (pok_sem_id_t* __user)args->arg2);
}

pok_ret_t pok_semaphore_status(pok_sem_id_t id,
    pok_semaphore_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_SEMAPHORE_STATUS(const pok_syscall_args_t* args)
{
    return pok_semaphore_status(
        (pok_sem_id_t)args->arg1,
        (pok_semaphore_status_t* __user)args->arg2);
}
#endif

#ifdef POK_NEEDS_EVENTS
pok_ret_t pok_event_create(const char* __user name,
    pok_event_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_EVENT_CREATE(const pok_syscall_args_t* args)
{
    return pok_event_create(
        (const char* __user)args->arg1,
        (pok_event_id_t* __user)args->arg2);
}

pok_ret_t pok_event_set(pok_event_id_t id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_EVENT_SET(const pok_syscall_args_t* args)
{
    return pok_event_set(
        (pok_event_id_t)args->arg1);
}
   
pok_ret_t pok_event_reset(pok_event_id_t id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_EVENT_RESET(const pok_syscall_args_t* args)
{
    return pok_event_reset(
        (pok_event_id_t)args->arg1);
}

pok_ret_t pok_event_wait(pok_event_id_t id,
    const pok_time_t* __user timeout);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_EVENT_WAIT(const pok_syscall_args_t* args)
{
    return pok_event_wait(
        (pok_event_id_t)args->arg1,
        (const pok_time_t* __user)args->arg2);
}

pok_ret_t pok_event_id(const char* __user name,
    pok_event_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_EVENT_ID(const pok_syscall_args_t* args)
{
    return pok_event_id(
        (const char* __user)args->arg1,
        (pok_event_id_t* __user)args->arg2);
}

pok_ret_t pok_event_status(pok_event_id_t id,
    pok_event_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_INTRA_EVENT_STATUS(const pok_syscall_args_t* args)
{
    return pok_event_status(
        (pok_event_id_t)args->arg1,
        (pok_event_status_t* __user)args->arg2);
}
#endif


#ifdef POK_NEEDS_ERROR_HANDLING
pok_ret_t pok_error_thread_create(uint32_t stack_size,
    void* __user entry);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_ERROR_HANDLER_CREATE(const pok_syscall_args_t* args)
{
    return pok_error_thread_create(
        (uint32_t)args->arg1,
        (void* __user)args->arg2);
}

pok_ret_t pok_error_raise_application_error(const char* __user msg,
    size_t msg_size);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_ERROR_RAISE_APPLICATION_ERROR(const pok_syscall_args_t* args)
{
    return pok_error_raise_application_error(
        (const char* __user)args->arg1,
        (size_t)args->arg2);
}

pok_ret_t pok_error_get(pok_error_status_t* __user status,
    void* __user msg);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_ERROR_GET(const pok_syscall_args_t* args)
{
    return pok_error_get(
        (pok_error_status_t* __user)args->arg1,
        (void* __user)args->arg2);
}

#endif

         /* Middleware syscalls */
#ifdef POK_NEEDS_PORTS_SAMPLING
pok_ret_t pok_port_sampling_create(const char* __user name,
    pok_port_size_t size,
    pok_port_direction_t direction,
    const pok_time_t* __user refresh,
    pok_port_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_SAMPLING_CREATE(const pok_syscall_args_t* args)
{
    return pok_port_sampling_create(
        (const char* __user)args->arg1,
        (pok_port_size_t)args->arg2,
        (pok_port_direction_t)args->arg3,
        (const pok_time_t* __user)args->arg4,
        (pok_port_id_t* __user)args->arg5);
}

pok_ret_t pok_port_sampling_write(pok_port_id_t id,
    const void* __user data,
    pok_port_size_t len);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_SAMPLING_WRITE(const pok_syscall_args_t* args)
{
    return pok_port_sampling_write(
        (pok_port_id_t)args->arg1,
        (const void* __user)args->arg2,
        (pok_port_size_t)args->arg3);
}

pok_ret_t pok_port_sampling_read(pok_port_id_t id,
    void* __user data,
    pok_port_size_t* __user len,
    pok_bool_t* __user valid);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_SAMPLING_READ(const pok_syscall_args_t* args)
{
    return pok_port_sampling_read(
        (pok_port_id_t)args->arg1,
        (void* __user)args->arg2,
        (pok_port_size_t* __user)args->arg3,
        (pok_bool_t* __user)args->arg4);
}

pok_ret_t pok_port_sampling_id(const char* __user name,
    pok_port_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_SAMPLING_ID(const pok_syscall_args_t* args)
{
    return pok_port_sampling_id(
        (const char* __user)args->arg1,
        (pok_port_id_t* __user)args->arg2);
}

pok_ret_t pok_port_sampling_status(pok_port_id_t id,
    pok_port_sampling_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_SAMPLING_STATUS(const pok_syscall_args_t* args)
{
    return pok_port_sampling_status(
        (pok_port_id_t)args->arg1,
        (pok_port_sampling_status_t* __user)args->arg2);
}

pok_ret_t pok_port_sampling_check(pok_port_id_t id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_SAMPLING_CHECK(const pok_syscall_args_t* args)
{
    return pok_port_sampling_check(
        (pok_port_id_t)args->arg1);
}
#endif /* POK_NEEDS_PORTS_SAMPLING */

#ifdef POK_NEEDS_PORTS_QUEUEING
pok_ret_t pok_port_queuing_create_packed(const char* __user name,
    const pok_port_queuing_create_arg_t* __user arg,
    pok_port_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_QUEUEING_CREATE(const pok_syscall_args_t* args)
{
    return pok_port_queuing_create_packed(
        (const char* __user)args->arg1,
        (const pok_port_queuing_create_arg_t* __user)args->arg2,
        (pok_port_id_t* __user)args->arg3);
}

pok_ret_t pok_port_queuing_send(pok_port_id_t id,
    const void* __user data,
    pok_port_size_t len,
    const pok_time_t* __user timeout);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_QUEUEING_SEND(const pok_syscall_args_t* args)
{
    return pok_port_queuing_send(
        (pok_port_id_t)args->arg1,
        (const void* __user)args->arg2,
        (pok_port_size_t)args->arg3,
        (const pok_time_t* __user)args->arg4);
}

pok_ret_t pok_port_queuing_receive(pok_port_id_t id,
    const pok_time_t* __user timeout,
    void* __user data,
    pok_port_size_t* __user len);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_QUEUEING_RECEIVE(const pok_syscall_args_t* args)
{
    return pok_port_queuing_receive(
        (pok_port_id_t)args->arg1,
        (const pok_time_t* __user)args->arg2,
        (void* __user)args->arg3,
        (pok_port_size_t* __user)args->arg4);
}

pok_ret_t pok_port_queuing_id(const char* __user name,
    pok_port_id_t* __user id);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_QUEUEING_ID(const pok_syscall_args_t* args)
{
    return pok_port_queuing_id(
        (const char* __user)args->arg1,
        (pok_port_id_t* __user)args->arg2);
}

pok_ret_t pok_port_queuing_status(pok_port_id_t id,
    pok_port_queuing_status_t* __user status);
static inline pok_ret_t pok_syscall_wrapper_POK_SYSCALL_MIDDLEWARE_QUEUEING_STATUS(const pok_syscall_args_t* args)
{
    return pok_port_queuing_status(
        (pok_port_id_t)args->arg1,
        (pok_port_queuing_status_t* __user)args->arg2);
}
#endif /* POK_NEEDS_PORTS_QUEUEING */