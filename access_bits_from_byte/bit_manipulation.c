#include <stdio.h>

// print 8 bits of an integer
void print_int_bits(int * ptr){

    int print_byte;
    
    for (int i = 7; i >= 0; i--){
        print_byte = *ptr >> i & 1;
        printf("%i ", print_byte);
    }
    puts("");

}


void bit_set(){
    int a = 0b00000000;
    //set the bit three bits from right
    a |= (1 << 3);

    print_int_bits(&a);

}

void bit_reset(){
    int a = 0b11111111;

    //reset bit three from right by ANDing with bitwise NOT of desired bit
    a &= ~(1 << 3);

    print_int_bits(&a);
}

void bit_toggle(){

    int a = 0b00000100;
    //toggle third bit from right by XORing with
    a ^= (1 << (3 - 1));

    print_int_bits(&a);

}



int main(){

    bit_set();
    bit_reset();
    bit_toggle();

    return 0;
}