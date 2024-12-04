#include <stdio.h>

// print 8 bits of an integer

void print_int_bits(int *ptr)
{
    int print_byte;

    int i = 8;

    while (i--)
    {
        printf("%i ", (*ptr >> i) & 1);
    }

    //could be done with a for loop:
    //for(int i = 8; i > 0; i--, printf("%i ", (*ptr >> i) & 1)){}

    //can be done with %b starting in c23
    //printf("%b \r\n", *ptr);

    puts("");
}

void bit_direct()
{
    int n = 7;
    int v = 1;

    int a = 0b0011100;

    a = a & ~(1 << n) | (v << n);

    print_int_bits(&a);
}

void bit_set()
{
    int a = 0b00000000;
    // set the bit three bits from right
    a |= (1 << 3);

    print_int_bits(&a);
}

void bit_reset()
{
    int a = 0b11111111;

    // reset bit three from right by ANDing with bitwise NOT of desired bit
    a &= ~(1 << 3);

    print_int_bits(&a);
}

void bit_toggle()
{

    int a = 0b00001000;
    // toggle third bit from right by XORing with a one shifted to desired position
    a ^= (1 << 3);

    print_int_bits(&a);
}

int main()
{

    bit_set();
    bit_reset();
    bit_toggle();
    bit_direct();

    return 0;
}