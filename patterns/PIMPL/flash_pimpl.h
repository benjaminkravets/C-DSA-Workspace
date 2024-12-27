#include <iostream>
#include <memory>

class Flash
{
public:
    Flash();
    ~Flash();
    int read(int addr, int byte_count, char *read_buffer);

private:
    class FlashImplementation;
    std::unique_ptr<FlashImplementation> ptr_implementation;
};