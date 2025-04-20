// C program to show thread functions 
  
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>
#include <math.h>


// Unaligned access may not be allowed
// uint32_t unaligned_access(void)
// {
//     uint8_t buffer[6] = {0xAA, 0xBB, 0xCC, 0xDD, 0xEE, 0xFF};
//     uint8_t i = 0;
//     uint32_t val_BB_to_EE = *((uint32_t *)( &buffer[0] ));

//     printf("%i \r\n", val_BB_to_EE);
//     printf("%i \r\n", 0xDDCCBBAA);
// }

union {
    float a;
    uint32_t b;
} float_bits;

void floats() {
    printf("\r\ns e e e e e e e e m m m m m m m m m m m m m m m m m m m m m m m\r\n");

    //the stored 8-bit exponent is the actual exponent + 127
    float_bits.a = .75; 

    for(int i = 31; i >= 0; i--) {
        printf("%i ", 1 & (float_bits.b >> i));
    }
}




typedef struct {
    int hi[3];
} gpio_struct;

gpio_struct gpio_conf_init() {
    gpio_struct A = {{1,2,3}};
    return A;
}




int main() 
{
    //unaligned_access();
    bit_bits();

    //printf("%i \r\n", gpio_conf_init().hi[2]);
    

    // float_bits.a = 1.0;
    
    // printf("%i \r\n", float_bits.b);

    // bit_printer(float_bits.b);


    
} 