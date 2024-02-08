#include <bitset>
#include <iostream>
 
using namespace std;

struct {
    
   unsigned int bit_one : 1;
   unsigned int bit_two : 1;
   
   unsigned int bits_threefour : 2;
   
} struct_bitfield;

 
int main()
{
 
    struct_bitfield.bit_two = 0;
    struct_bitfield.bits_threefour = 1;
    
   
        
}