#include <assert.h>
#include <stdio.h>


char full_name[30];




int main () {

   //what does this do
   char *text = calloc(1,1), buffer[32];

   // unsigned char input[20];

   // fgets(input, sizeof(input), stdin);

   // printf("%s \r\n", input);

   unsigned int a = 1;

   struct {
      unsigned int x : 1;
      unsigned int y : 1;
      unsigned int z : 1;
      unsigned int x1 : 1;
      unsigned int y1 : 1;
      unsigned int z1 : 1;

   } status;

   status.x = 101;
   status.y = 0;

   printf("%i %i \r\n", status.x, status.y);

   printf("%i \r\n", sizeof(status));

   return 0;
}