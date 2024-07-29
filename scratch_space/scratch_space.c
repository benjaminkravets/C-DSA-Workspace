#include <assert.h>
#include <stdio.h>




void print_int(int ints_to_print[10]){

   for (int i = 0; i < 10; i++){
      printf("%i \r\n", *(ints_to_print+i));
   }

}


int main () {


   int my_ints[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};


   print_int(my_ints);






   


}