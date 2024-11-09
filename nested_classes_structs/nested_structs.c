#include <stdio.h>

struct outer_struct
{
    struct inner_struct
    {
        int a;
    } innter_struct_instance;
};

void nested_structs()
{
    struct outer_struct outer_struct_instance;

    outer_struct_instance.innter_struct_instance.a = 2;

    printf("%i \n", outer_struct_instance.innter_struct_instance.a);
}

int main(int argc, char *argv[])
{
    nested_structs();

    return 0;
}