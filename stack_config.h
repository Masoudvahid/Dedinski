/*
 * Copyright (C) 2023, Masoud Vahid
 * Stack config file
 */
#define CANNARY_GUARD 1
//#define HASH_GUARD    2

#ifndef _MSTACK_CONFIG_
#define _MSTACK_CONFIG_

// #include "stack.h"

enum StackSecLevel{
    STK_SECURITY_LEVEL_ZERO = 0,
    STK_SECURITY_LEVEL_CAN,
    STK_SECURITY_LEVEL_HASH
};

typedef unsigned long long canary_t;
const int STK_MIN_CAPACITY = 10;


#ifdef CANNARY_GUARD
    const canary_t CAN1               = 0xCAFEBABEDE;
    const canary_t CAN2               = 0xBADFACEBED;
    const canary_t CAN1DATA           = 0xFADEDBEEFB;
    const canary_t CAN2DATA           = 0xBEDEFFACED;
    const int      STK_SECURITY_LEVEL = STK_SECURITY_LEVEL_CAN; 
#elif defined(HASH_GUARD)
    const int STK_SECURITY_LEVEL      = STK_SECURITY_LEVEL_HASH; 
#else
    const int STK_SECURITY_LEVEL      = STK_SECURITY_LEVEL_ZERO; 
#endif


#endif //_MSTACK_CONFIG_