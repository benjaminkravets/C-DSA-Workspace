#include <iostream>

//Two namespaces can be declared in a single file
namespace space_one
{
    void print_greeting(){
        std::cout << "Hello namespace 1! \r\n";
    }

    namespace space_two
    {
        void print_greeting(){
            std::cout << "Hello namespace 2! \r\n";
        }

        int space_two_value = 1;
    }
}


//Only one of thesee namespaces can be used since they contain a common function
using namespace space_one::space_two;

int main(){

    print_greeting();

    std::cout << space_one::space_two::space_two_value << std::endl;
    
    return 0;
}

