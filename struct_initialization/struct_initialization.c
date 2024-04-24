#include <stdio.h>
#include <stdlib.h>

// define a struct type but no instance
struct struct_type_1
{
    int a;
    char b;
    double c;
};

typedef struct struct_type_2
{
    int a;
    char b;
    double c;
} struct_type_2_type;

struct struct_type_3
{
    int a;
    char b;
    double c;
} type_3_instance;

int main()
{

    // define instance of struct_type_1
    struct struct_type_1 type_1_instance;

    type_1_instance.a = 1;
    type_1_instance.b = 'a';
    type_1_instance.c = 1.234;

    printf("%i, %c, %f, \r\n", type_1_instance.a, type_1_instance.b, type_1_instance.c);


    // define two instances of struct type 2 using struct and using typedef
    struct struct_type_2 type_2_instance_1;

    type_2_instance_1.a = 2;
    type_2_instance_1.b = 'b';
    type_2_instance_1.c = 2.345;

    printf("%i, %c, %f, \r\n", type_2_instance_1.a, type_2_instance_1.b, type_2_instance_1.c);

    struct_type_2_type type_2_instance_2;

    type_2_instance_2.a = 3;
    type_2_instance_2.b = 'c';
    type_2_instance_2.c = 3.456;

    printf("%i, %c, %f, \r\n", type_2_instance_2.a, type_2_instance_2.b, type_2_instance_2.c);


    // use defined instance of struct_type_3
    type_3_instance.a = 4;
    type_3_instance.b = 'd';
    type_3_instance.c = 4.567;

    printf("%i, %c, %f, \r\n", type_3_instance.a, type_3_instance.b, type_3_instance.c);

    return 0;
}