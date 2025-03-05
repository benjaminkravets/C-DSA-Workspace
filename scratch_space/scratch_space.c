// C program to show thread functions 
  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

int i_HelloWorld() {
    printf("Hello world\r\n");
}
  
int main() 
{ 
    uint8_t v = -1;
    printf("%i \r\n", v);

    return 0; 
} 