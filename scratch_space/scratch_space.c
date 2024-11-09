#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

struct A
{
    struct B *b;
};

struct B
{
    struct A *a;
};

int main()
{
    struct A g;
    struct B h;
}
