#include <stdio.h>

__intptr_t get_stack_pointer()
{
    register char *stack_ptr asm("sp");
}

void anotherone()
{
    printf("%p \r\n", get_stack_pointer());
}

void main()
{
    anotherone();
}