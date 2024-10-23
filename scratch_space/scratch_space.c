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
    struct b b_0;
    struct a a_0;
    b_0.a_0 = &a_0;

    struct b * b_0_ptr = &b_0;

    b_0_ptr->a_0->a0 = 2;

    printf("%i \r\n", b_0_ptr->a_0->a0);
    

}
