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
    int (*a)();
    a = i_HelloWorld;
    a();

    return 0; 
} 