#include <stdio.h>


int main(){

    int number = 5; // 0101 in binary
    int bit_position = 1;

    number |= (1 << bit_position); // Sets the 2nd bit to 1 (becomes 0111)

    printf("C = %i \r\n", number);
}