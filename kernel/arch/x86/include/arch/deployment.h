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
 * This file also incorporates work covered by POK License.
 * Copyright (c) 2007-2009 POK team
 */

/* Definitions which are used in deployment.c */

#ifndef __JET_X86_DEPLOYMENT_H__
#define __JET_X86_DEPLOYMENT_H__

/* 
 * Description of one user space.
 */
struct ja_x86_space
{
    /*
     * Physical address of memory chunk.
     * 
     * If it is set to 0 in deployment.c, it will be filled upon space initialization.
     */
    uintptr_t   phys_base;
    
    /* 
     * Total size for partition's use.
     * 
     * Calculated upon space initialization.
     */
    size_t size_total;
    
    /* 
     * Size of the memory for normal use.
     * 
     * Set in deployment.c.
     */
    size_t      size_normal;
    /*
     * Size of the memory for stacks, above size_normal.
     * 
     * Set in deployment.c.
     */
    size_t size_stack;
    
    /*
     * Memory currently used for stacks.
     */
    size_t size_stack_used;
};

/*
 * Array of user space descriptions.
 * 
 * Should be defined in deployment.c.
 */
extern struct ja_x86_space ja_spaces[];
extern int ja_spaces_n;

#endif /* __JET_PPC_DEPLOYMENT_H__ */