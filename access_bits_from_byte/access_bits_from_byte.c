//from https://stackoverflow.com/users/2361316/joe

#include <stdio.h>
#include <stdlib.h>

int main()
{
    unsigned
        input = 0b0111u,
        n_bits = 4u,
        *bits = (unsigned*)malloc(sizeof(unsigned) * n_bits),
        bit = 0;

    for(bit = 0; bit < n_bits; ++bit)
        bits[bit] = (input >> bit) & 1;

    for(bit = n_bits; bit--;)
        printf("%u", bits[bit]);
    printf("\n");

    free(bits);
}