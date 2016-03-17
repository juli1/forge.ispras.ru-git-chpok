#ifndef __POK_KERNEL_PORT_H__
#define __POK_KERNEL_PORT_H__

/* ARINC ports. */

#include <core/channel.h>
#include <core/thread.h>
#include <common.h>
struct _pok_patition_arinc;

typedef enum
{
	 POK_PORT_DIRECTION_IN   = 1,
	 POK_PORT_DIRECTION_OUT  = 2
} pok_port_directions_t;

typedef enum
{
	 POK_PORT_KIND_QUEUEING  = 1,
	 POK_PORT_KIND_SAMPLING  = 2,
	 POK_PORT_KIND_INVALID   = 10
} pok_port_kinds_t;


/* 
 * Queuing port. 
 * 
 * Contain common parts for "in" and "out" ports +
 * "union"ed in- and out-specific parts.
 */
typedef struct
{
    /* 
     * Name of the port.
     * 
     * Should be set initially.
     */
    const char                  *name;
    /*
     * Queue of waited threads.
     */
    pok_thread_wq_t             waiters;
    
    /*
     * Channel to which port is connected.
     * 
     * Should be set initially.
     * 
     * Note, that reverse link (channel->port) is set on CREATE_QUEUING_PORT.
     */
    pok_channel_queuing_t       *channel;

    /*
     * Direction (IN or OUT).
     * 
     * Should be set initially.
     */
    pok_port_directions_t       direction;
    
    /*
     * Queuing discipline.
     * 
     * Set on port creation.
     */
    pok_queuing_discipline_t    discipline;

    /* 
     * Partition to which port belongs to.
     * It is needed for notification callback, because it is called
     * by the other channel's side.
     * 
     * Should be set initially.
     */
    struct _pok_patition_arinc *partition;

    /* Whether port has been created (with CREATE_QUEUING_PORT)*/
    pok_bool_t                  is_created;
    
    /* 
     * Whether port has been notified by the channel.
     * 
     * This flag is intended to be cleared after every check.
     */
    pok_bool_t                  is_notified;
    
    /* Direction-specific parts. */
    union {
        pok_channel_queuing_sender_t sender; // OUT
        pok_channel_queuing_reciever_t receiver; // IN
    };

} pok_port_queuing_t;

/* Status for queuing port, for return into user space. */
typedef struct
{
   pok_port_size_t      nb_message;
   pok_port_size_t      max_nb_message;
   pok_port_size_t      max_message_size;
   pok_port_direction_t direction;
   uint8_t              waiting_processes;
} pok_port_queuing_status_t;

// Initialize queuing port.
void pok_port_queuing_init(pok_port_queuing_t* port_queuing);


pok_ret_t pok_port_queuing_create(
    const char* __user              name,
    pok_port_size_t                 message_size,
    pok_port_size_t                 max_nb_message,
    pok_port_direction_t            direction,
    pok_queuing_discipline_t        discipline,
    pok_port_id_t* __user           id);

pok_ret_t pok_port_queuing_receive(
    pok_port_id_t               id, 
    const pok_time_t* __user    timeout, 
    pok_port_size_t             maxlen, 
    void* __user                data, 
    pok_port_size_t* __user     len);


pok_ret_t pok_port_queuing_send(
    pok_port_id_t               id, 
    const void* __user          data,
    pok_port_size_t             len,
    const pok_time_t __user    timeout);


pok_ret_t pok_port_queuing_status(
    pok_port_id_t               id,
    pok_port_queuing_status_t* __user status);

pok_ret_t pok_port_queuing_id(
    const char* __user name,
    pok_port_id_t* __user id);

/* 
 * Receive message from the port into specified process.
 * 
 * Port should be available for read.
 * 
 * Thread should have address for reading to in its `wait_private` field.
 * After the call, function will set this field to +len.
 * 
 * Should be called with local preemption disabled.
 */
void port_queuing_receive(pok_port_queuing_t* port, pok_thread_t* t);

/* 
 * Send message into the port from specified process.
 * 
 * Port should be available for write.
 * 
 * Thread should have message parameters stored  in its `wait_private` field
 * as pok_message_send_t structure.
 * 
 * After the call, function will set this field to +len.
 * 
 * Should be called with local preemption disabled.
 */
void port_queuing_send(pok_port_queuing_t* port, pok_thread_t* t);


/* 
 * Samling port. 
 * 
 * Contain common parts for "in" and "out" ports +
 * refresh_period for "in" port.
 */
typedef struct
{
    /* 
     * Name of the port.
     * 
     * Should be set initially.
     */
    const char                  *name;
    
    /*
     * Channel to which port is connected.
     * 
     * Should be set initially.
     */
    pok_channel_sampling_t       *channel;

    /*
     * Direction (IN or OUT).
     * 
     * Should be set initially.
     */
    pok_port_directions_t       direction;

    /* Whether port has been created (with CREATE_SAMPLING_PORT)*/
    pok_bool_t                  is_created;

    /* Refresh period for IN port. */
    pok_time_t                  refresh_period;
    
    /* Validity of last message read from the port. */
    pok_bool_t                  last_message_validity;
} pok_port_sampling_t;

/* Status for sampling port, for return into user space. */
typedef struct
{
    pok_port_size_t         size;
    pok_port_direction_t    direction;
    uint64_t                refresh;
    bool_t                  validity;
} pok_port_sampling_status_t;

// Initialize sampling port
void pok_port_sampling_init(pok_port_sampling_t* port_sampling);


pok_ret_t pok_port_sampling_create(
    const char*             name,
    pok_port_size_t         size,
    pok_port_direction_t    direction,
    uint64_t                refresh,
    pok_port_id_t           *id
);

pok_ret_t pok_port_sampling_write(
    pok_port_id_t           id,
    const void              *data,
    pok_port_size_t         len
);

pok_ret_t pok_port_sampling_read(
    pok_port_id_t           id,
    void                    *data,
    pok_port_size_t         *len,
    bool_t                  *valid
);

pok_ret_t pok_port_sampling_id(
    const char              *name,
    pok_port_id_t           *id
);

pok_ret_t pok_port_sampling_status (
    const pok_port_id_t         id,
    pok_port_sampling_status_t  *status
);


#endif /* __POK_KERNEL_PORT_H__ */
