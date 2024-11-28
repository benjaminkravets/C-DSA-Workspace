#include <stdio.h>

int add(int a, int b){
    asm("addl %1, %0" : "+r" (a) : "rm" (b));
    return a;
}

int main()
{
    int foo = 1;

    asm("inc %[IncrementMe]" : [IncrementMe] "+r" (foo));

    printf("%i \r\n", add(1,1));

}