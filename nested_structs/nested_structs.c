#include <stdio.h>

struct outer_struct
{
    struct inner_struct
    {
        int a;
    } innter_struct_instance;

};



int main(int argc, char *argv[])
{
    struct outer_struct outer_struct_instance;

    outer_struct_instance.innter_struct_instance.a = 2;

    printf("%i \n", outer_struct_instance.innter_struct_instance.a);

    return 0;
}