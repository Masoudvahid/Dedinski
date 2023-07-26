#include "stack.h"
#include "stack_config.h"
#include "log.h"

static int stack_ok (stack_t* stk)
{
    if (stk == nullptr)
        return STK_NULL_PTR;
    if (stk->capacity < 1)
        return STK_CAPACITY_NULL;
    if (stk->size > stk->capacity)
        return STK_BAD_SIZE;
    if (stk->size < 0)
        return STK_BAD_SIZE;

#ifdef CANNARY_GUARD
    if (stk->can1 != (long long)&stk->can1)
        return STK_CAN1_ERROR;
    if (stk->can2 != (long long)&stk->can2)
        return STK_CAN2_ERROR;

#endif

#if HASH_GUARD
    if (stk->stack_hash != calc_hash(stk))
        return STK_HASH_RUINED;
#endif
    return STK_OK;
}


long long calc_hash(stack_t* stk) {
    uint32_t hash = 0;

    for(int i = 0; i < stk->size; i++) {
        hash += ((unsigned int)*((char*)stk->data - sizeof(long long) + i)) * i;
    }

    for (int i = 0; i < (stk->capacity + 2 * sizeof (long long) - 1); i++)
    {
        hash += ((unsigned int)*((char*)stk->data - sizeof(long long) + i)) * i;
    }

    return hash;
}

//size_t calc_data_hash(stack_t* stk)
//{
//    if (stk == nullptr)
//    {
//        return (size_t) STK_NULL_PTR;
//    }
//
//    size_t hash = 0;
//
//    if (stk->data != nullptr && StackIsDestructed(stk) != STACK_IS_DESTRUCTED && stk->stackHash == SetStackHash(stk))
//    {
//        hash += HashCalculate((char *) stk->data, stk->capacity * sizeof(Elem_t));
//    }
//    else
//    {
//        stk->status |= STACK_DATA_IS_RUINED;
//        StackDump(stk);
//    }
//
//    return hash;
//}

stack_t* stack_init_func(stack_t* stk, size_t init_capacity,
                         const char name[], size_t line,
                         const char file[], const char func[])
{
    if (stk == nullptr) return nullptr;

    (stk->info).name = name;
    (stk->info).func = func;
    (stk->info).file = file;
    (stk->info).line = line;

    stk->capacity    = (init_capacity < STK_MIN_CAPACITY) ? STK_MIN_CAPACITY : init_capacity;
    stk->size        = 0;

    // Security assignment
    stk->security_level = STK_SECURITY_LEVEL;
#ifdef CANNARY_GUARD
        stk->can1 = CAN1;
        stk->can2 = CAN2;
#endif
#ifdef HASH_GUARD
        stk->security_level = STK_SECURITY_LEVEL_HASH;
        stk->data_hash      = 0;
#endif

    // Data allocation
    char* data_ptr = nullptr;
    data_ptr = (char *) calloc(init_capacity, init_capacity * sizeof(elem_t) + 2 * sizeof(canary_t));

    if (data_ptr == nullptr) {
        stk->status |= STK_MEM_ALLOC_FAILED;

        return stk;
    }

    // Data security guard
    stk->data = (elem_t*) (data_ptr + sizeof(canary_t));

#ifdef CANNARY_GUARD
        stk->data = (elem_t*) (data_ptr + sizeof(canary_t));

        *((canary_t*)  data_ptr)                                                      = CAN1DATA;
        *((canary_t*) (data_ptr + sizeof(canary_t) + sizeof(elem_t) * init_capacity)) = CAN2DATA;
#endif

#ifdef HASH_GUARD
    stk->stack_hash = calc_hash(stk);
//    stk->data_hash  = SetStackDataHash(stk);
#endif

    stk->status = STK_OK;

    stack_ok(stk);

    return stk;
    // LOG("Stack_init with\n");
    // stack_dump()
    // uint8_t* data = (uint8_t*)stk;
}




/*
void stack_dump(stack_t* stk, size_t line, const char file[], const char func[])
{

    fprintf(LogFile, "\n---------------------------StackDump---------------------------------------\n");

    if (stk->status & STK_NULL_PTR)
    {
        fprintf(LogFile, "Stack's pointer is null\n");
    }

    fprintf(LogFile, "Called at %s at %s(%lu)\n", file, func, line);
    fprintf(LogFile, "Stack[%p] <%s> at %s at %s(%lu)\n", stk, (stk->info).name, (stk->info).func,
                                                  (stk->info).file, (stk->info).line);
    fprintf(LogFile, "Stack status:\n");


    StackVerify(stk);

    if (stk->status & STACK_DATA_IS_RUINED)
    {
        fprintf(LogFile, "\t\t!!!STACK'S DATA IS RUINED!!!\n");
    }

    #define StatPrint_(STATUS, text) \
        if (stk->status & STATUS)          \
        {                                   \
            fprintf(LogFile, #text "\n");    \
        }

    StatPrint_(STACK_IS_EMPTY,                 >>>Stack is empty);
    StatPrint_(STACK_IS_DESTRUCTED,            >>>Stack is destructed);
    StatPrint_(STACK_UB,                       >>>Stack has undefined behavior);
    StatPrint_(STACK_BAD_RESIZE,               >>>Stack has resize problem);
    StatPrint_(CAN_NOT_ALLOCATE_MEMORY,        >>>Allocate memory problems);
    StatPrint_(STACK_SIZE_MORE_THAN_CAPACITY,  >>>Stack size more than capacity);
    StatPrint_(STACK_DATA_NULL_PTR,            >>>Stack data pointer is null);

#if CANARY_GUARD
    StatPrint_(STACK_LEFT_CANARY_RUINED,       >>>Stack left canary is ruined);
    StatPrint_(STACK_RIGHT_CANARY_RUINED,      >>>Stack right canary is ruined);
    StatPrint_(STACK_DATA_LEFT_CANARY_RUINED,  >>>Stack data left canary is ruined);
    StatPrint_(STACK_DATA_RIGHT_CANARY_RUINED, >>>Stack data right canary is ruined);
#endif

#if HASH_GUARD
    StatPrint_(STACK_HASH_IS_RUINED,           >>>Stack hash is ruined);
    StatPrint_(STACK_DATA_HASH_IS_RUINED,      >>>Stack data hash is ruined);
#endif

    if (!stk->status)
    {
        fprintf(LogFile, ">>>Stack is OK\n");
    }

    fprintf(LogFile, "{\n");

#if HASH_GUARD
    fprintf(LogFile, "    STACK HASH:  %lx    STACK DATA HASH: %lx\n",  stk->stackHash, stk->dataHash);
#endif

#if CANARY_GUARD
    fprintf(LogFile, "    LEFT CANARY: %llx   RIGHT CANARY:    %llx\n", stk->leftCanary, stk->rightCanary);
#endif

    fprintf(LogFile, "    data pointer = %p\n", stk->data);

    if (StackIsDestructed(stk) == STACK_IS_DESTRUCTED)
    {
        fprintf(LogFile, "    size         = %lx\n", stk->size);
        fprintf(LogFile, "    capacity     = %lx\n", stk->capacity);

    }
    else if (!(stk->status & (STACK_DATA_NULL_PTR | STACK_IS_EMPTY)))
    {
        fprintf(LogFile, "    size         = %lu\n", stk->size);
        fprintf(LogFile, "    capacity     = %lu\n", stk->capacity);

#if CANARY_GUARD
        fprintf(LogFile, "    DATA LEFT CANARY: %llx   DATA RIGHT CANARY: %llx\n",
                              *((Canary_t*) ((char*) stk->data - sizeof(Canary_t))),
                              *((Canary_t*) ((char*) stk->data + sizeof(Elem_t) * stk->capacity)));
#endif
        fprintf(LogFile, "    {\n");

        for (size_t index = 0; index < stk->capacity; ++index)
        {
            fprintf(LogFile, "\t");
            fprintf(LogFile, (index < stk->size) ? "*" : " ");
            fprintf(LogFile, "[%lu] = ", index);

            print(LogFile, stk->data[index]);

#if CANARY_GUARD
            if (index >= stk->size)
            {
               fprintf(LogFile, " (POISON)");
            }
#endif
            fprintf(LogFile, "\n");
        }
        fprintf(LogFile, "    }\n");
    }

    fprintf(LogFile, "}\n");
    fprintf(LogFile, "\n---------------------------------------------------------------------------\n");

    #undef StatPrint_
}
*/



StackStatus stack_push(stack_t* stk, const elem_t value) {
    if (stk == nullptr)
    {
//        StackDump(stk);
        return STK_NULL_PTR;
    }

//    ASSERT_OK(stk);

//    StackResize(stk, UP);
    if (stk->data == nullptr)
    {
//        StackDump(stk);

        return (StackStatus) stk->status;
    }

    stk->data[stk->size++] = value;

//#if HASH_GUARD
    stk->stack_hash = calc_hash(stk);
//    stk->data_hash  = SetStackDataHash(stk);
//#endif

//    ASSERT_OK(stk);


    // if (stack->size == stack->capacity) {...}
    // stack->data[stack->size] = value; ++stack_size
    //if (stack_push(stack, 10)) {
        // Error occured
    //}
    return STK_OK;
}

elem_t stack_pop(stack_t* stk)
{
    if (stk == nullptr)
    {
//        StackDump(stk);
        throw std::runtime_error("StackPop: nullptr stack");
//        return ?;
    }

//    ASSERT_OK(stk);

    if (stk->size == 0)
    {

#if HASH_GUARD
        stk->stackHash = SetStackHash(stk);
#endif
//        StackDump(stk);

        throw std::runtime_error("StackPop: empty stack");
//        return ?;
    }

    elem_t delElem     = stk->data[--stk->size];

#if CANARY_GUARD
    stk->data[stk->size] = POISON;
    stk->stackHash = SetStackHash(stk);
    stk->dataHash  = SetStackDataHash(stk);
#else
    stk->data[stk->size] = 0;
#endif

#if HASH_GUARD
    stk->stack_hash = calc_hash(stk);
    stk->data_hash  = SetStackDataHash(stk);
#endif

//    StackResize(stk, DOWN);
    if (stk->data == nullptr)
    {
//        StackDump(stk);

        return stk->status;
    }

#if HASH_GUARD
    stk->stack_hash = calc_hash(stk);
    stk->data_hash  = SetStackDataHash(stk);
#endif

//    ASSERT_OK(stk);

    return delElem;
}

StackStatus stack_is_empty(stack_t* stk)
{
    if (stk == nullptr)
    {
        return STK_NULL_PTR;
    }

    if (stk->size == 0)
    {
        return STK_EMPTY;
    }

    return STK_I_DONT_KNOW;
}

