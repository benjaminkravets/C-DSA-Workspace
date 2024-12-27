#include "flash_pimpl.h"
// third_party.h // large third part inclusion

#include <iostream>

class Flash::FlashImplementation
{
public:
    int read(int addr, int byte_count, char *read_buffer)
    {
        std::cout << "reading bytes" << std::endl;
    }

private:
    // third_party_obj obj_0;
    int size;
    char jedec_id;
};

Flash::Flash() : ptr_implementation(std::make_unique<FlashImplementation>()) {}

Flash::~Flash() = default;

int Flash::read(int addr, int byte_count, char *read_buffer) {
    ptr_implementation->read(511, 2, 0);
};


int main() {
    
}