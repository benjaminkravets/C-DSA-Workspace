#include <bitset>
#include <iostream>
 
using namespace std;

// from https://stackoverflow.com/questions/111928/is-there-a-printf-converter-to-print-in-binary-format
// Assumes little endian

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

struct {
    
   unsigned int bit_one : 1;
   unsigned int bit_two : 1;
   
   unsigned int bits_threefour : 2;
   
} struct_bitfield;

 
int main()
{
    struct_bitfield.bit_one = 1;
    struct_bitfield.bit_two = 0;
    struct_bitfield.bits_threefour = 1;
    cout << "bit field: ";
    printBits(1, &struct_bitfield);
   
    bitset<8> my_bitset_decimal(19);
    bitset<8> my_bitset_string(string("1010"));

    cout << "bit set decimal: " << my_bitset_decimal << " bit set string: " << my_bitset_string << endl << endl;
    
    
    bitset<6> all_zeroes(0);
    
    cout << "Bitset (all zeroes): " << all_zeroes << endl;
    
    all_zeroes.set(3);
    all_zeroes.set(5);

    cout << "Bitset (set bit 3 and 5): " << all_zeroes << endl;
    cout << "Bitset (count of set bits): " << all_zeroes.count() << endl;
    cout << all_zeroes <<  " is " << all_zeroes.to_ulong();

    
}