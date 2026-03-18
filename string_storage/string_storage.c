#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char string_1[14]; // uninitialized global stored in .bss
char string_2[14] = "aaaaaaaaaaa"; // initialized global stored in .data
const char string_6[14] = "bbbbbbbbbbbbb"; // const stored in .rodata



int main()
{

    strcpy(string_1, "cccccccccccc"); // "cccccccccc" (the argument to strcpy) is stored in .text since it is an argument
    
    char string_3[14] = "dddddddddd"; // local stored in stack

    char * string_4 = (char *)malloc(14); // dynamically allocated stored in heap (pointer itself is on stack)

    strcpy(string_4, "eeeeeeee"); // "eeeeeeee" (the argument to strcpy) is stored in .text since it is an argument

    static char string_5[14] = "fffffffffffff"; // local static stored in .data

    printf("\r\n");

    return 0;

}