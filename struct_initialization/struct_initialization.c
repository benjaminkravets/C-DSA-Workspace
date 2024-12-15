#include <stdio.h>
#include <stdlib.h>

// define a struct type but no instance
struct struct_type_1
{
    int a;
    char b;
    double c;
};

// use struct_type_2_type to refer to struct struct_type_2
typedef struct struct_type_2
{
    int a;
    char b;
    double c;
} struct_type_2_type;

// create struct and an instance of it
struct struct_type_3
{
    int a;
    char b;
    double c;

} type_3_instance;

// create struct instance without a type
struct
{
    int a;
    char b;
    double c;
} type_4_instance;

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

    // use designated initializer:

    struct_type_2_type type_2_instance_3 = {
        .a = 5,
        .b = 'e',
        .c = 5.678};

    printf("%i, %c, %f, \r\n", type_2_instance_3.a, type_2_instance_3.b, type_2_instance_3.c);

    // assign values to struct instance with no defined type
    type_4_instance.a = 6;
    type_4_instance.b = 'f';
    type_4_instance.c = 6.789;

    printf("%i, %c, %f, \r\n", type_4_instance.a, type_4_instance.b, type_4_instance.c);

    struct_type_2_type type_2_instance_4 = {
        7,
        'g',
        7.890};

    printf("%i, %c, %f, \r\n", type_2_instance_4.a, type_2_instance_4.b, type_2_instance_4.c);

    return 0;
}