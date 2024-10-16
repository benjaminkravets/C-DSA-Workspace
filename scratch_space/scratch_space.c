#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

int vla(int a){
    char vla_buffer[a];
    memset(vla_buffer, 0, a);
    return 0;
}

int main()
{
    vla(100000000);
}