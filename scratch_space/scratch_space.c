#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>


struct a {
    int a0;
};

struct b {
    struct a * a_0;
};

int main()
{
    register char* stack_ptr asm("sp");
    printf("%p", stack_ptr);
    
}
