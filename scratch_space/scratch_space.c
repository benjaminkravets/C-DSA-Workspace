#include <assert.h>
#include <stdio.h>


void modify(int a[static 3]){

   for(int y = 0; y < 5; y++){
      a[y] = 5;
   }
}


int main () {


   char input[20];

   fgets(input, sizeof(input), stdin);

   printf("%s \r\n", input);

   // int b[7] = {1, 2, 3};


   // modify(b);

   // for(int y = 0; y < 5; y++){
   //    printf("%i ", b[y]);
   // }


}