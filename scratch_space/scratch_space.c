#include <assert.h>
#include <stdio.h>


char str[20] = "check";
int d = 12345;

int outer_function(int a, int b){

   return a + b;
   
}

int main () {

   int c = outer_function();

   printf("%i", c);

   return 0;
}