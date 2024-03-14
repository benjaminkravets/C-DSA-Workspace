#include <iostream>

//Two namespaces can be declared in a single file
namespace space_one
{
    void print_greeting(){
        std::cout << "Hello namespace 1! \r\n";
    }
}
namespace space_two
{
    void print_greeting(){
        std::cout << "Hello namespace 2! \r\n";
    }
}

//Only one of thesee namespaces can be used since they contain a common function
using namespace space_two;

int main(){

    print_greeting();
    //The other namespace can still be used.
    space_one::print_greeting();
    return 0;
}

