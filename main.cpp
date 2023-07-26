#include <iostream>
#include <stdio.h>
#include "stack.h"

//FILE* LogFile = startLog(LogFile);

 
int main() {
    stack_t stk = {};

    stack_init(&stk, 75);
    stack_push(&stk, 1);
    std::cout << (stack_is_empty(&stk) == STK_EMPTY) << "\n";
    std::cout << stack_pop(&stk) << "\n";
    std::cout << (stack_is_empty(&stk) == STK_EMPTY)  << "\n";   // DONT LIKE THE WAY IT LOOKS
//    StackDump(&stk);

 
}
 