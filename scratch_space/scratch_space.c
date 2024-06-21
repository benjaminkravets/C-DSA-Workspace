#include <assert.h>
#include <stdio.h>




struct {
   __int8_t a;
   __int8_t b;
   char c;



} my_struct_instance;


int main () {


   // char input[20];

   // fgets(input, sizeof(input), stdin);

   // printf("%s \r\n", input);

   int a = 2;

   int * b = &a;

   *b = 1;


   printf("%i \r\n", *b);


}