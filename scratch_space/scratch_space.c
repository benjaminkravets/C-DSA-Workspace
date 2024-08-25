#include <stdlib.h>
#include <stdio.h>

char string_s[] = "Hi there";
char **string_t = &string_s;


typedef struct struct_type
{
    __uint8_t a;
    __uint32_t b;
    __uint8_t c;

} my_struct_type;

my_struct_type struct_instance;

void down_here(){

    struct_instance.a = 'a';
    struct_instance.b = 'b';
    struct_instance.c = 'c';

    printf("%p %p %p %p \n", &struct_instance, &struct_instance.a, &struct_instance.b, &struct_instance.c);

    //printf("%s \n", string_t);
}

void up_here(){
    char *p = "hello";
    char q[] = "hello"; // no need to count this

    printf("%zu\n", sizeof(p)); // => size of pointer to char -- 4 on x86, 8 on x86-64
    printf("%zu\n", sizeof(q)); // => size of char array in memory -- 6 on both

    // size_t strlen(const char *s) and we don't get any warnings here:
    printf("%zu\n", strlen(p)); // => 5
    printf("%zu\n", strlen(q)); // => 5

    return 0;
}



int main(int argc, char *argv[])
{

    int prog = 1;

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