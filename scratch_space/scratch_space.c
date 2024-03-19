#include <stdio.h>


int main(){

    __uint16_t i = 1;

    i = i << 9;


    printf("%i \r\n", i);

    __uint16_t address = 3<<9 | 0;

    printf("%i \r\n", address);

}