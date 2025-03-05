module;

#include <iostream>

export module flash_module;

namespace flash_namespace
{
    export class Flash
    {
        int size;

    public:
        void read();
        void write();
    };
    export void flash_init()
    {
        std::cout << "Flash init" << std::endl;
    }
}