/*
 * Copyright (C) 2023, Masoud Vahid
 * Stack implementation
 */

#ifndef _MSTACK_
#define _MSTACK_

#include <iostream>
#include <stdio.h>
#include <malloc.h>
#include "log.h"
#include "stack_config.h"

typedef int elem_t;

struct stack_info {
    // For debugging purposes only!
    const char* name; // Name of the structure
    const char* func; // Function signature
    const char* file; // Patht to the file
    size_t      line;   // Number of the line
};

struct stack_t {
    size_t      size;
    size_t      capacity;
    elem_t*     data;
    stack_info  info;

    canary_t    can1;
    canary_t    can2;

    uint32_t    stack_hash;
    uint32_t    data_hash;
    
    int         security_level;
    int         status;
};

enum StackStatus{
    STK_OK                       = 0 << 0,
    STK_EMPTY                    = 1 << 1,
    STK_MEM_ALLOC_FAILED         = 1 << 2,
    STK_NULL_PTR                 = 1 << 3,
    STK_CAPACITY_NULL            = 1 << 4,
    STK_BAD_SIZE                 = 1 << 5,
    STK_SIZE_MORE_THAN_CAPACITY  = 1 << 6,
    STK_I_DONT_KNOW              = 1 << 11,

#if CANNARY_GUARD
    STK_CAN1_ERROR       = 1 << 7,
    STK_CAN2_ERROR       = 1 << 8,
    STK_CAN1_VALUE_ERROR = 1 << 9,
    STK_CAN2_VALUE_ERROR = 1 << 10,
#endif

#if HASH_GUARD
    STK_HASH_RUINED = 1 << 11
#endif
};




#define stack_init(stk, capacity) \
    stack_init_func(stk, capacity, #stk, __LINE__, __FILE__, __PRETTY_FUNCTION__)


#define StackDump(stk) \
    StackDumpFunc(stk, __LINE__, __FILE__, __PRETTY_FUNCTION__)


long long calc_hash        (stack_t*   stk);

stack_t*  stack_init_func(stack_t*   stk, size_t     init_capacity,
                          const char name[], size_t     line,
                          const char file[], const char func[]);


void stack_dump(stack_t* stk, size_t line, const char file[], const char func[]);


StackStatus stack_push(stack_t* stk, const elem_t value);

elem_t stack_pop(stack_t* stk);

StackStatus stack_is_empty(stack_t* stk);


#endif // _MSTACK_