#include <stdio.h>


int min(int a, int b){
    return (a < b) ? a : b;
}
int main(){
    int c = min(54, 6);
    printf("%i \r\n", c);
}