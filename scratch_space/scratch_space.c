#include <assert.h>
#include <stdio.h>


char full_name[30];


int main () {

   //what does this do
   char *text = calloc(1,1), buffer[32];

   unsigned char input[20];

   fgets(input, sizeof(input), stdin);

   printf("%s \r\n", input);

   return 0;
}