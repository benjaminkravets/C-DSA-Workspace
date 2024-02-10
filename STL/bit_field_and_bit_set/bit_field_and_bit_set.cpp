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
    
   
    bitset<8> my_bitset_decimal(19);
    bitset<8> my_bitset_string(string("1010"));

    cout << my_bitset_decimal << " " << my_bitset_string;
}