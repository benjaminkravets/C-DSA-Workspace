#include <stdio.h>

void printBits(size_t const size, void const * const ptr)
{
    unsigned char *b = (unsigned char*) ptr;
    unsigned char byte;
    int i, j;
    
    for (i = size-1; i >= 0; i--) {
        for (j = 7; j >= 0; j--) {
            byte = (b[i] >> j) & 1;
            printf("%u", byte);
        }
    }
    puts("");
}


void bit_set(){
    int a = 0b00000000;
    //set the bit three bits from right
    a |= (1 << 3);

    printBits(1, &a);

}

void bit_reset(){
    int a = 0b11111111;

    //reset bit three from right by ANDing with bitwise NOT of desired bit
    a &= ~(1 << 3);

    printBits(1, &a);
}

void bit_toggle(){

    int a = 0b00000100;
    //toggle third bit from right by XORing with
    a ^= (1 << (3 - 1));

    printBits(1, &a);

}

int main(){
    bit_set();
    bit_reset();
    bit_toggle();

}