#include <iostream>
#include <stdio.h>

void define_undefine(){

    //Macros can be both defined and undefined
    #define ONE 1
    //This will be fine
    std::cout << ONE << std::endl;
    #undef ONE
    //This will cause error
    //std::cout << ONE << std::endl;
    return;  
}

void check_if_defined(){
    #define ONE 1

    #ifdef ONE
        std::cout << "This gets compiled" << std::endl;
    #endif

    #ifndef TWO
        std::cout << "This gets compiled" << std::endl;
    #else
        std::cout << "This gets compiled instead" << std::endl;    
    #endif
    
    return;

}

void print_line(){

    //The line number can be accessed and modified using the #line directive
    std::cout << __LINE__ << std::endl;

    #line 20 "macros.cpp"

    std::cout << __LINE__ << std::endl;
    return;
}

void error(){

    #ifndef TWO
    #error TWO This is an error!
    #endif

    return;

}

void pragma_message(){
    #ifndef TWO
    #pragma message("Two not defined")
    #endif

    return;
}




int main(){
    define_undefine();
    check_if_defined();
    print_line();
    pragma_message();
}




