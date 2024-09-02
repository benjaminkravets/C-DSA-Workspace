
#include <stdio.h>

void fn1(){
    printf("fn1 called \n");
    return 0;
}

int main(){

    void * fn1_address = &fn1;

    printf("fn1 at %p \n", fn1_address);

    void (*func_ptr)(void) = (void (*)())fn1_address;

    func_ptr();


}