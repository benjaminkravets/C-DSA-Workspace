#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string_1[14]; // uninitialized global stored in .bss
char string_2[14] = "Hello World 2"; // initialized global stored in .data
const char string_6[14] = "Hellow World 6"; // const stored in .rodata



int main()
{

    strcpy(string_1, "Hello World 1"); // "Hello World 1" (the argument to strcpy) is stored in .text since it is an argument
    
    char string_3[14] = "Hello World 3"; // local stored in stack

    char * string_4 = (char *)malloc(14); // dynamically allocated stored in heap (pointer itself is on stack)

    strcpy(string_4, "Hello World 4"); // "Hello World 4" (the argument to strcpy) is stored in .text since it is an argument

    static char string_5[14] = "Hello World 5"; // local static stored in .data

    printf("\r\n");

    return 0;

}