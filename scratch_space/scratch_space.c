#include <stdlib.h>
#include <stdio.h>

void up_here()
{

    return 0;
}

void down_here()
{
    //char a[] = "string literal";
    char *p = "string literal";
    char *name_2 = "test str 3";

    //a[0] = 'a';
    //p = 'a';

    void * ga;

    printf("%s \n", p);

    printf("%i \n", sizeof(ga));

    return 0;
}

int main(int argc, char *argv[])
{

    int prog = 2;

    switch (prog)
    {
    case 1:
        up_here();
        break;

    case 2:
        down_here();
        break;

    default:
        break;
    }
}