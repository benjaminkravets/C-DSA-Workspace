#include <iostream>

//Two namespaces can be declared in a single file
namespace space_one
{
    void print_greeting_1(){
        std::cout << "Hello namespace 1! \r\n";
    }
}

//This can be extended
namespace space_one
{
    void print_greeting_2(){
        std::cout << "Hello namespace 2! \r\n";
    }
}


int main(){

    space_one::print_greeting_1();
    space_one::print_greeting_2();
    return 0;
}