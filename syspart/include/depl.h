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

#ifndef __POK_DEPL_H__
#define __POK_DEPL_H__

#include <arinc653/types.h>
#include <middleware/port.h>
#include <port_info.h>
#include <pci.h>
#include <channel_driver.h>
#include <arinc653/queueing.h>
#include <arinc653/sampling.h>

#define ARRAY_SIZE(x) (sizeof(x) / sizeof(x[0]))
#define IP_ADDR(a,b,c,d) ((uint32_t)((a) & 0xff) << 24) | \
                         ((uint32_t)((b) & 0xff) << 16) | \
                         ((uint32_t)((c) & 0xff) << 8)  | \
                          (uint32_t)((d) & 0xff)
//for afdx
#define MAX_AFDX_PAYLOAD_SIZE 	64
#define MAX_NB_MESSAGE 			10
#define VL_PER_PORT				1

extern sys_sampling_port_t sys_sampling_ports[];
extern sys_queuing_port_t  sys_queuing_ports[];
extern unsigned sys_sampling_ports_nb;
extern unsigned sys_queuing_ports_nb;

enum protocol_kind {
    UDP,
//  RS232,
};

typedef struct {
    uint32_t ip;
    uint16_t port;
} udp_data_t;

typedef struct
{
    uint32_t port_index;
    void *driver_data;
    channel_driver_t *driver_ptr;
} sys_channel_t;


struct mac_ip {
    uint32_t ip;
    uint8_t mac[6];
};

//for afdx

typedef struct {
	QUEUING_PORT_NAME_TYPE name;
	MESSAGE_SIZE_TYPE	msg_size;
	MESSAGE_RANGE_TYPE	max_nb_msg;
	PORT_DIRECTION_TYPE	port_dir;
	QUEUING_DISCIPLINE_TYPE	que_disc;
} queuing_port_config_t;

extern uint16_t config_queuing_port_list_size;
extern queuing_port_config_t config_queuing_port_list[];

//
extern unsigned sys_sampling_channels_nb;
extern sys_channel_t sys_sampling_channels[];
extern unsigned sys_queuing_channels_nb;
extern sys_channel_t sys_queuing_channels[];
extern struct mac_ip mac_addr_mapping[];
extern unsigned mac_addr_mapping_nb;
extern channel_driver_t *channel_drivers[];
extern unsigned channel_drivers_nb;

void drivers_init(void);


extern struct pci_driver pci_driver_table[];
extern unsigned pci_driver_table_size;

extern char *ipnet_netdev_name;

#endif
