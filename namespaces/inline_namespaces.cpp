#include <iostream>

//One namespace can be nested in another and directly addressable using the outer namespace

namespace space_one
{
    inline namespace space_two
    {
        void print_greeting(){
            std::cout << "Hello namespace 2! \r\n";
        }
    }
}

using namespace space_one;

int main(){

    print_greeting();
    return 0;
}