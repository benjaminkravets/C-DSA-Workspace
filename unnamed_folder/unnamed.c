#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// Many expressions values can share one statement
void cases_share_code()
{
    // printf will be called for 0-2
    int a = 0;

    switch (a)
    {
    case 0:
    case 1:
    case 2:
        printf("Hi \r\n");
        break;

    default:
        break;
    }
}

// Can increment and dereference pointer in one step
void increment_and_dereference()
{
    int ints[] = {1, 2, 3, 4, 5};
    int *foo = ints;

    for (int i = 0; i < 5; i++)
    {
        printf("%i \r\n", *foo++);
    }
}

// Some compilers allow multi-character constants (accesible by register shift)
// https://stackoverflow.com/a/3684046

void multi_char_constants()
{
    const uint8_t a = 'dcba';

    printf("%c ", a >> 0);
    printf("%c ", a >> 8);
    printf("%c ", a >> 16);
    printf("%c ", a >> 24);
}

int main()
{
    // cases_share_code();
    // increment_and_dereference();
    multi_char_constants();
}