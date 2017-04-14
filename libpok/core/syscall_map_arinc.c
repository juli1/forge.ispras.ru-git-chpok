/*
 * GENERATED! DO NOT MODIFY!
 *
 * Instead of modifying this file, modify the one it generated from (kernel/include/uapi/syscall_map_arinc.h.in).
 */

#include <core/syscall.h>
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
#include <uapi/error_arinc_types.h>
#include <uapi/memblock_types.h>
#include <uapi/msection.h>
#include <uapi/ippc_types.h>

pok_ret_t _pok_thread_create_impl(const char* name,
    void* entry,
    const pok_thread_attr_t* attr,
    pok_thread_id_t* thread_id)
{
    return pok_syscall4(POK_SYSCALL_THREAD_CREATE,
        (uint32_t)name,
        (uint32_t)entry,
        (uint32_t)attr,
        (uint32_t)thread_id);
}

pok_ret_t pok_thread_create(const char* name,
    void* entry,
    const pok_thread_attr_t* attr,
    pok_thread_id_t* thread_id)
__attribute__ ((weak, alias ("_pok_thread_create_impl")));

pok_ret_t _pok_thread_sleep_impl(const pok_time_t* time)
{
    return pok_syscall1(POK_SYSCALL_THREAD_SLEEP,
        (uint32_t)time);
}

pok_ret_t pok_thread_sleep(const pok_time_t* time)
__attribute__ ((weak, alias ("_pok_thread_sleep_impl")));

pok_ret_t _pok_sched_end_period_impl(void)
{
    return pok_syscall0(POK_SYSCALL_THREAD_PERIOD);
}

pok_ret_t pok_sched_end_period(void)
__attribute__ ((weak, alias ("_pok_sched_end_period_impl")));

pok_ret_t _pok_thread_suspend_impl(const pok_time_t* time)
{
    return pok_syscall1(POK_SYSCALL_THREAD_SUSPEND,
        (uint32_t)time);
}

pok_ret_t pok_thread_suspend(const pok_time_t* time)
__attribute__ ((weak, alias ("_pok_thread_suspend_impl")));

pok_ret_t _pok_thread_get_status_impl(pok_thread_id_t thread_id,
    char* name,
    void** entry,
    pok_thread_status_t* status)
{
    return pok_syscall4(POK_SYSCALL_THREAD_STATUS,
        (uint32_t)thread_id,
        (uint32_t)name,
        (uint32_t)entry,
        (uint32_t)status);
}

pok_ret_t pok_thread_get_status(pok_thread_id_t thread_id,
    char* name,
    void** entry,
    pok_thread_status_t* status)
__attribute__ ((weak, alias ("_pok_thread_get_status_impl")));

pok_ret_t _pok_thread_delayed_start_impl(pok_thread_id_t thread_id,
    const pok_time_t* time)
{
    return pok_syscall2(POK_SYSCALL_THREAD_DELAYED_START,
        (uint32_t)thread_id,
        (uint32_t)time);
}

pok_ret_t pok_thread_delayed_start(pok_thread_id_t thread_id,
    const pok_time_t* time)
__attribute__ ((weak, alias ("_pok_thread_delayed_start_impl")));

pok_ret_t _pok_thread_set_priority_impl(pok_thread_id_t thread_id,
    uint32_t priority)
{
    return pok_syscall2(POK_SYSCALL_THREAD_SET_PRIORITY,
        (uint32_t)thread_id,
        (uint32_t)priority);
}

pok_ret_t pok_thread_set_priority(pok_thread_id_t thread_id,
    uint32_t priority)
__attribute__ ((weak, alias ("_pok_thread_set_priority_impl")));

pok_ret_t _pok_thread_resume_impl(pok_thread_id_t thread_id)
{
    return pok_syscall1(POK_SYSCALL_THREAD_RESUME,
        (uint32_t)thread_id);
}

pok_ret_t pok_thread_resume(pok_thread_id_t thread_id)
__attribute__ ((weak, alias ("_pok_thread_resume_impl")));

pok_ret_t _pok_thread_suspend_target_impl(pok_thread_id_t thread_id)
{
    return pok_syscall1(POK_SYSCALL_THREAD_SUSPEND_TARGET,
        (uint32_t)thread_id);
}

pok_ret_t pok_thread_suspend_target(pok_thread_id_t thread_id)
__attribute__ ((weak, alias ("_pok_thread_suspend_target_impl")));

pok_ret_t _pok_thread_yield_impl(void)
{
    return pok_syscall0(POK_SYSCALL_THREAD_YIELD);
}

pok_ret_t pok_thread_yield(void)
__attribute__ ((weak, alias ("_pok_thread_yield_impl")));

pok_ret_t _pok_sched_replenish_impl(const pok_time_t* budget)
{
    return pok_syscall1(POK_SYSCALL_THREAD_REPLENISH,
        (uint32_t)budget);
}

pok_ret_t pok_sched_replenish(const pok_time_t* budget)
__attribute__ ((weak, alias ("_pok_sched_replenish_impl")));

pok_ret_t _pok_thread_stop_target_impl(pok_thread_id_t thread_id)
{
    return pok_syscall1(POK_SYSCALL_THREAD_STOP,
        (uint32_t)thread_id);
}

pok_ret_t pok_thread_stop_target(pok_thread_id_t thread_id)
__attribute__ ((weak, alias ("_pok_thread_stop_target_impl")));

pok_ret_t _pok_thread_stop_impl(void)
{
    return pok_syscall0(POK_SYSCALL_THREAD_STOPSELF);
}

pok_ret_t pok_thread_stop(void)
__attribute__ ((weak, alias ("_pok_thread_stop_impl")));

pok_ret_t _pok_thread_find_impl(const char* name,
    pok_thread_id_t* id)
{
    return pok_syscall2(POK_SYSCALL_THREAD_FIND,
        (uint32_t)name,
        (uint32_t)id);
}

pok_ret_t pok_thread_find(const char* name,
    pok_thread_id_t* id)
__attribute__ ((weak, alias ("_pok_thread_find_impl")));


pok_ret_t _jet_resched_impl(void)
{
    return pok_syscall0(POK_SYSCALL_RESCHED);
}

pok_ret_t jet_resched(void)
__attribute__ ((weak, alias ("_jet_resched_impl")));

pok_ret_t _jet_msection_enter_helper_impl(struct msection* section)
{
    return pok_syscall1(POK_SYSCALL_MSECTION_ENTER_HELPER,
        (uint32_t)section);
}

pok_ret_t jet_msection_enter_helper(struct msection* section)
__attribute__ ((weak, alias ("_jet_msection_enter_helper_impl")));

pok_ret_t _jet_msection_wait_impl(struct msection* section,
    const pok_time_t* timeout)
{
    return pok_syscall2(POK_SYSCALL_MSECTION_WAIT,
        (uint32_t)section,
        (uint32_t)timeout);
}

pok_ret_t jet_msection_wait(struct msection* section,
    const pok_time_t* timeout)
__attribute__ ((weak, alias ("_jet_msection_wait_impl")));

pok_ret_t _jet_msection_notify_impl(struct msection* section,
    pok_thread_id_t thread_id)
{
    return pok_syscall2(POK_SYSCALL_MSECTION_NOTIFY,
        (uint32_t)section,
        (uint32_t)thread_id);
}

pok_ret_t jet_msection_notify(struct msection* section,
    pok_thread_id_t thread_id)
__attribute__ ((weak, alias ("_jet_msection_notify_impl")));

pok_ret_t _jet_msection_wq_notify_impl(struct msection* section,
    struct msection_wq* wq,
    pok_bool_t is_all)
{
    return pok_syscall3(POK_SYSCALL_MSECTION_WQ_NOTIFY,
        (uint32_t)section,
        (uint32_t)wq,
        (uint32_t)is_all);
}

pok_ret_t jet_msection_wq_notify(struct msection* section,
    struct msection_wq* wq,
    pok_bool_t is_all)
__attribute__ ((weak, alias ("_jet_msection_wq_notify_impl")));

pok_ret_t _jet_msection_wq_size_impl(struct msection* section,
    struct msection_wq* wq,
    size_t* size)
{
    return pok_syscall3(POK_SYSCALL_MSECTION_WQ_SIZE,
        (uint32_t)section,
        (uint32_t)wq,
        (uint32_t)size);
}

pok_ret_t jet_msection_wq_size(struct msection* section,
    struct msection_wq* wq,
    size_t* size)
__attribute__ ((weak, alias ("_jet_msection_wq_size_impl")));


pok_ret_t _pok_partition_set_mode_current_impl(pok_partition_mode_t mode)
{
    return pok_syscall1(POK_SYSCALL_PARTITION_SET_MODE,
        (uint32_t)mode);
}

pok_ret_t pok_partition_set_mode_current(pok_partition_mode_t mode)
__attribute__ ((weak, alias ("_pok_partition_set_mode_current_impl")));

pok_ret_t _pok_current_partition_get_status_impl(pok_partition_status_t* status)
{
    return pok_syscall1(POK_SYSCALL_PARTITION_GET_STATUS,
        (uint32_t)status);
}

pok_ret_t pok_current_partition_get_status(pok_partition_status_t* status)
__attribute__ ((weak, alias ("_pok_current_partition_get_status_impl")));

pok_ret_t _pok_current_partition_inc_lock_level_impl(int32_t* lock_level)
{
    return pok_syscall1(POK_SYSCALL_PARTITION_INC_LOCK_LEVEL,
        (uint32_t)lock_level);
}

pok_ret_t pok_current_partition_inc_lock_level(int32_t* lock_level)
__attribute__ ((weak, alias ("_pok_current_partition_inc_lock_level_impl")));

pok_ret_t _pok_current_partition_dec_lock_level_impl(int32_t* lock_level)
{
    return pok_syscall1(POK_SYSCALL_PARTITION_DEC_LOCK_LEVEL,
        (uint32_t)lock_level);
}

pok_ret_t pok_current_partition_dec_lock_level(int32_t* lock_level)
__attribute__ ((weak, alias ("_pok_current_partition_dec_lock_level_impl")));


pok_ret_t _pok_error_thread_create_impl(uint32_t stack_size,
    void* entry)
{
    return pok_syscall2(POK_SYSCALL_ERROR_HANDLER_CREATE,
        (uint32_t)stack_size,
        (uint32_t)entry);
}

pok_ret_t pok_error_thread_create(uint32_t stack_size,
    void* entry)
__attribute__ ((weak, alias ("_pok_error_thread_create_impl")));

pok_ret_t _pok_error_raise_application_error_impl(const char* msg,
    size_t msg_size)
{
    return pok_syscall2(POK_SYSCALL_ERROR_RAISE_APPLICATION_ERROR,
        (uint32_t)msg,
        (uint32_t)msg_size);
}

pok_ret_t pok_error_raise_application_error(const char* msg,
    size_t msg_size)
__attribute__ ((weak, alias ("_pok_error_raise_application_error_impl")));

pok_ret_t _pok_error_get_impl(pok_error_status_t* status,
    void* msg)
{
    return pok_syscall2(POK_SYSCALL_ERROR_GET,
        (uint32_t)status,
        (uint32_t)msg);
}

pok_ret_t pok_error_get(pok_error_status_t* status,
    void* msg)
__attribute__ ((weak, alias ("_pok_error_get_impl")));

pok_ret_t _pok_error_raise_os_error_impl(const char* msg,
    size_t msg_size)
{
    return pok_syscall2(POK_SYSCALL_ERROR_RAISE_OS_ERROR,
        (uint32_t)msg,
        (uint32_t)msg_size);
}

pok_ret_t pok_error_raise_os_error(const char* msg,
    size_t msg_size)
__attribute__ ((weak, alias ("_pok_error_raise_os_error_impl")));


   /* Middleware syscalls */
pok_ret_t _pok_port_sampling_create_impl(const char* name,
    pok_port_size_t size,
    pok_port_direction_t direction,
    const pok_time_t* refresh,
    pok_port_id_t* id)
{
    return pok_syscall5(POK_SYSCALL_MIDDLEWARE_SAMPLING_CREATE,
        (uint32_t)name,
        (uint32_t)size,
        (uint32_t)direction,
        (uint32_t)refresh,
        (uint32_t)id);
}

pok_ret_t pok_port_sampling_create(const char* name,
    pok_port_size_t size,
    pok_port_direction_t direction,
    const pok_time_t* refresh,
    pok_port_id_t* id)
__attribute__ ((weak, alias ("_pok_port_sampling_create_impl")));

pok_ret_t _pok_port_sampling_write_impl(pok_port_id_t id,
    const void* data,
    pok_port_size_t len)
{
    return pok_syscall3(POK_SYSCALL_MIDDLEWARE_SAMPLING_WRITE,
        (uint32_t)id,
        (uint32_t)data,
        (uint32_t)len);
}

pok_ret_t pok_port_sampling_write(pok_port_id_t id,
    const void* data,
    pok_port_size_t len)
__attribute__ ((weak, alias ("_pok_port_sampling_write_impl")));

pok_ret_t _pok_port_sampling_read_impl(pok_port_id_t id,
    void* data,
    pok_port_size_t* len,
    pok_bool_t* valid)
{
    return pok_syscall4(POK_SYSCALL_MIDDLEWARE_SAMPLING_READ,
        (uint32_t)id,
        (uint32_t)data,
        (uint32_t)len,
        (uint32_t)valid);
}

pok_ret_t pok_port_sampling_read(pok_port_id_t id,
    void* data,
    pok_port_size_t* len,
    pok_bool_t* valid)
__attribute__ ((weak, alias ("_pok_port_sampling_read_impl")));

pok_ret_t _pok_port_sampling_id_impl(const char* name,
    pok_port_id_t* id)
{
    return pok_syscall2(POK_SYSCALL_MIDDLEWARE_SAMPLING_ID,
        (uint32_t)name,
        (uint32_t)id);
}

pok_ret_t pok_port_sampling_id(const char* name,
    pok_port_id_t* id)
__attribute__ ((weak, alias ("_pok_port_sampling_id_impl")));

pok_ret_t _pok_port_sampling_status_impl(pok_port_id_t id,
    pok_port_sampling_status_t* status)
{
    return pok_syscall2(POK_SYSCALL_MIDDLEWARE_SAMPLING_STATUS,
        (uint32_t)id,
        (uint32_t)status);
}

pok_ret_t pok_port_sampling_status(pok_port_id_t id,
    pok_port_sampling_status_t* status)
__attribute__ ((weak, alias ("_pok_port_sampling_status_impl")));

pok_ret_t _pok_port_sampling_check_impl(pok_port_id_t id)
{
    return pok_syscall1(POK_SYSCALL_MIDDLEWARE_SAMPLING_CHECK,
        (uint32_t)id);
}

pok_ret_t pok_port_sampling_check(pok_port_id_t id)
__attribute__ ((weak, alias ("_pok_port_sampling_check_impl")));

pok_ret_t _pok_port_queuing_create_packed_impl(const char* name,
    const pok_port_queuing_create_arg_t* arg,
    pok_port_id_t* id)
{
    return pok_syscall3(POK_SYSCALL_MIDDLEWARE_QUEUEING_CREATE,
        (uint32_t)name,
        (uint32_t)arg,
        (uint32_t)id);
}

pok_ret_t pok_port_queuing_create_packed(const char* name,
    const pok_port_queuing_create_arg_t* arg,
    pok_port_id_t* id)
__attribute__ ((weak, alias ("_pok_port_queuing_create_packed_impl")));

pok_ret_t _pok_port_queuing_send_impl(pok_port_id_t id,
    const void* data,
    pok_port_size_t len,
    const pok_time_t* timeout)
{
    return pok_syscall4(POK_SYSCALL_MIDDLEWARE_QUEUEING_SEND,
        (uint32_t)id,
        (uint32_t)data,
        (uint32_t)len,
        (uint32_t)timeout);
}

pok_ret_t pok_port_queuing_send(pok_port_id_t id,
    const void* data,
    pok_port_size_t len,
    const pok_time_t* timeout)
__attribute__ ((weak, alias ("_pok_port_queuing_send_impl")));

pok_ret_t _pok_port_queuing_receive_impl(pok_port_id_t id,
    const pok_time_t* timeout,
    void* data,
    pok_port_size_t* len)
{
    return pok_syscall4(POK_SYSCALL_MIDDLEWARE_QUEUEING_RECEIVE,
        (uint32_t)id,
        (uint32_t)timeout,
        (uint32_t)data,
        (uint32_t)len);
}

pok_ret_t pok_port_queuing_receive(pok_port_id_t id,
    const pok_time_t* timeout,
    void* data,
    pok_port_size_t* len)
__attribute__ ((weak, alias ("_pok_port_queuing_receive_impl")));

pok_ret_t _pok_port_queuing_id_impl(const char* name,
    pok_port_id_t* id)
{
    return pok_syscall2(POK_SYSCALL_MIDDLEWARE_QUEUEING_ID,
        (uint32_t)name,
        (uint32_t)id);
}

pok_ret_t pok_port_queuing_id(const char* name,
    pok_port_id_t* id)
__attribute__ ((weak, alias ("_pok_port_queuing_id_impl")));

pok_ret_t _pok_port_queuing_status_impl(pok_port_id_t id,
    pok_port_queuing_status_t* status)
{
    return pok_syscall2(POK_SYSCALL_MIDDLEWARE_QUEUEING_STATUS,
        (uint32_t)id,
        (uint32_t)status);
}

pok_ret_t pok_port_queuing_status(pok_port_id_t id,
    pok_port_queuing_status_t* status)
__attribute__ ((weak, alias ("_pok_port_queuing_status_impl")));

pok_ret_t _pok_port_queuing_clear_impl(pok_port_id_t id)
{
    return pok_syscall1(POK_SYSCALL_MIDDLEWARE_QUEUEING_CLEAR,
        (uint32_t)id);
}

pok_ret_t pok_port_queuing_clear(pok_port_id_t id)
__attribute__ ((weak, alias ("_pok_port_queuing_clear_impl")));



pok_ret_t _jet_memory_block_get_status_impl(const char* name,
    jet_memory_block_status_t* status)
{
    return pok_syscall2(POK_SYSCALL_MEMORY_BLOCK_GET_STATUS,
        (uint32_t)name,
        (uint32_t)status);
}

pok_ret_t jet_memory_block_get_status(const char* name,
    jet_memory_block_status_t* status)
__attribute__ ((weak, alias ("_jet_memory_block_get_status_impl")));

pok_ret_t _jet_ippc_partition_arinc_init_portal_impl(const char* portal_name,
    int* portal_id)
{
    return pok_syscall2(POK_SYSCALL_IPPC_INIT_PORTAL,
        (uint32_t)portal_name,
        (uint32_t)portal_id);
}

pok_ret_t jet_ippc_partition_arinc_init_portal(const char* portal_name,
    int* portal_id)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_init_portal_impl")));

pok_ret_t _jet_ippc_partition_arinc_call_impl(int portal_id,
    const struct jet_ippc_client_access_window* access_windows,
    int access_windows_n)
{
    return pok_syscall3(POK_SYSCALL_IPPC_CALL,
        (uint32_t)portal_id,
        (uint32_t)access_windows,
        (uint32_t)access_windows_n);
}

pok_ret_t jet_ippc_partition_arinc_call(int portal_id,
    const struct jet_ippc_client_access_window* access_windows,
    int access_windows_n)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_call_impl")));

pok_ret_t _jet_ippc_partition_arinc_get_portal_type_info_impl(const char* portal_name,
    int* portal_type_id,
    int* n_clients)
{
    return pok_syscall3(POK_SYSCALL_IPPC_GET_PORTAL_TYPE_INFO,
        (uint32_t)portal_name,
        (uint32_t)portal_type_id,
        (uint32_t)n_clients);
}

pok_ret_t jet_ippc_partition_arinc_get_portal_type_info(const char* portal_name,
    int* portal_type_id,
    int* n_clients)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_get_portal_type_info_impl")));

pok_ret_t _jet_ippc_partition_arinc_get_portal_info_impl(int server_portal_id,
    int* n_connections)
{
    return pok_syscall2(POK_SYSCALL_IPPC_GET_PORTAL_INFO,
        (uint32_t)server_portal_id,
        (uint32_t)n_connections);
}

pok_ret_t jet_ippc_partition_arinc_get_portal_info(int server_portal_id,
    int* n_connections)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_get_portal_info_impl")));

pok_ret_t _jet_ippc_partition_arinc_create_connections_impl(int server_portal_id,
    void* entry,
    size_t stack_size,
    int n_connections,
    pok_thread_id_t* thread_id)
{
    return pok_syscall5(POK_SYSCALL_IPPC_CREATE_CONNECTIONS,
        (uint32_t)server_portal_id,
        (uint32_t)entry,
        (uint32_t)stack_size,
        (uint32_t)n_connections,
        (uint32_t)thread_id);
}

pok_ret_t jet_ippc_partition_arinc_create_connections(int server_portal_id,
    void* entry,
    size_t stack_size,
    int n_connections,
    pok_thread_id_t* thread_id)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_create_connections_impl")));

pok_ret_t _jet_ippc_partition_arinc_return_impl(void)
{
    return pok_syscall0(POK_SYSCALL_IPPC_RETURN);
}

pok_ret_t jet_ippc_partition_arinc_return(void)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_return_impl")));

pok_ret_t _jet_ippc_partition_arinc_copy_to_client_impl(void* dst,
    const void* src,
    size_t n)
{
    return pok_syscall3(POK_SYSCALL_IPPC_COPY_TO_CLIENT,
        (uint32_t)dst,
        (uint32_t)src,
        (uint32_t)n);
}

pok_ret_t jet_ippc_partition_arinc_copy_to_client(void* dst,
    const void* src,
    size_t n)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_copy_to_client_impl")));

pok_ret_t _jet_ippc_partition_arinc_copy_from_client_impl(void* dst,
    const void* src,
    size_t n)
{
    return pok_syscall3(POK_SYSCALL_IPPC_COPY_FROM_CLIENT,
        (uint32_t)dst,
        (uint32_t)src,
        (uint32_t)n);
}

pok_ret_t jet_ippc_partition_arinc_copy_from_client(void* dst,
    const void* src,
    size_t n)
__attribute__ ((weak, alias ("_jet_ippc_partition_arinc_copy_from_client_impl")));