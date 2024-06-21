#include <stdio.h>
#include <string.h>

char string_1[14];
char string_2[14] = "Hello World 2"; // stored in .data

int main()
{
    char string_3[14] = "Hello World 3";

    strcpy(string_1, "Hello World 1"); // "Hello World 1" is stored in .text since it is an argument

    printf("%s %s %s \r\n", string_1, string_2, string_3); // "%s %s %s" is stored in .rodata

}