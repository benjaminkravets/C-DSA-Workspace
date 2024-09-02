#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>


#define BAR(X) printf("1 %i", X), printf("2 %i \n", X)
//#undef BAR(X)
//#define BAR(X) do {printf("1 %i", X); printf("2 %i \n", X);} while(0)

int main(){


    if (1)
        BAR(1);
    else
        printf("No \n");


}