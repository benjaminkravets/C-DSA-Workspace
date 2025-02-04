#include "flash_pimpl.h"
// third_party.h // large third part inclusion

#include <iostream>

// changes in the implementation details won't force recompilation of code
// that just uses Flash. Modifications to the implementation are confined to this file.
// The layout of the Flash class is now stable, regardless of implementation.

class Flash::FlashImplementation
{
public:
    int read(int addr, int byte_count, char *read_buffer)
    {
        std::cout << "reading bytes" << std::endl;
        return 0;
    }

private:
    // third_party_obj obj_0;
    int size;
    char jedec_id;
};

// provide definition of default constructor and initialize member ptr_implementation.
Flash::Flash() : ptr_implementation(std::make_unique<FlashImplementation>()) {}

Flash::~Flash() = default;

// provide implementation of read()
int Flash::read(int addr, int byte_count, char *read_buffer)
{
    return ptr_implementation->read(511, 2, 0);
};

int main()
{
    Flash flash0;
    flash0.read(1, 2, 0);
    return 0;
}