#include <iostream>

//Using a no name namespace is possible
namespace
{
    void print_greeting(){
        std::cout << "Hello namespace 1! \r\n";
    }
}

int main(){

    print_greeting();

    return 0;
}