#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>





int main()
{
    uint32_t a = 'dcba';

    printf("%c ", a >> 0);
    printf("%c ", a >> 8);
    printf("%c ", a >> 16);
    printf("%c ", a >> 24);
    
}