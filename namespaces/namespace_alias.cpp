#include <iostream>

namespace space_one
{
    void print_greeting(){
        std::cout << "Hello namespace 1! \r\n";
    }
}

namespace space_two = space_one;


using namespace space_two;

int main(){

    print_greeting();

    return 0;
}

