#include <stdio.h>
#include <stdlib.h>


int add(int x, int y){
    return x + y;
}

int subtract(int x, int y){
    return x - y;
}

typedef struct object {

    int a;
    int b;
    int (*func_ptr_0)(int, int);
    int (*func_ptr_1)(int, int);


} object_struct;


int main(){

    object_struct* object_0_ptr = (object_struct*)malloc(sizeof(object_struct));

    object_0_ptr->a = 1;
    object_0_ptr->b = 2;
    object_0_ptr->func_ptr_0 = &add;
    object_0_ptr->func_ptr_1 = &subtract;

    printf("%i \r\n", object_0_ptr->func_ptr_0(1,2));
    printf("%i \r\n", object_0_ptr->func_ptr_1(1,2));


}