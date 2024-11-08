#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// 1. Many expressions values can share one statement
void cases_share_code()
{
    // printf will be called for 0-2
    int a = 0;

    switch (a)
    {
    case 0:
    case 1:
    case 2:
        printf("Hi \r\n");
        break;

    default:
        break;
    }
}

// 2. Can increment and dereference pointer in one step
void increment_and_dereference()
{
    int ints[] = {1, 2, 3, 4, 5};
    int *foo = ints;

    for (int i = 0; i < 5; i++)
    {
        printf("%i \r\n", *foo++);
    }
}

// 3. Some compilers allow multi-character constants (accesible by register shift)
//  https://stackoverflow.com/a/3684046

void multi_char_constants()
{
    const uint32_t a = 'dcba';

    printf("%c ", a >> 0);
    printf("%c ", a >> 8);
    printf("%c ", a >> 16);
    printf("%c ", a >> 24);
}

// 4. Anonymous unions in structs
struct A_0
{
    union
    {
        char a;
        int b;
    };
} a;

void anonymous_union_in_struct()
{
    a.a = 'a';
    printf("%c", a.a);
    a.b = 1;
    printf("%i", a.b);
}

// 5. specify minimum array size (may only warn)
void minimum_array_size(int a[static 10])
{
}
void pass_array_of_size()
{
    int a[8] = {0};
    minimum_array_size(a);
}

// 6. gcc packed (distance between a and b is not the same, B "packs" everything together causing unaligned memory access)
struct A_1
{
    uint8_t b;
    uint32_t c;
};

struct __attribute__((__packed__)) B_1
{
    uint8_t b;
    uint32_t c;
};

void gcc_packed()
{
    struct A_1 a;
    struct B_1 b;

    printf("%p \r\n", &a.b);
    printf("%p \r\n", &a.c);

    printf("\r\n");

    printf("%p \r\n", &b.b);
    printf("%p \r\n", &b.c);
}

// 7. comma notation in for loop
void comma_notation()
{
    for (uint32_t i = 0; i < 10; i++, printf("%i \r\n", i))
    {
    }
}

// 8. no return
// try diassembling this both with an without the noreturn attribute (keep an eye on main)

void __attribute__((__noreturn__)) no_return_func()
{
    printf("Hi \r\n");
    exit(0);
};

// 9. function pointers

void jump_to()
{
    printf("fn1 called \n");
}

void function_pointer()
{
    void *fn1_address = &jump_to;

    printf("fn1 at %p \n", fn1_address);

    void (*func_ptr)(void) = (void (*)())fn1_address;

    func_ptr();
}

int main()
{
    // cases_share_code();
    // increment_and_dereference();
    // multi_char_constants();
    // anonymous_union_in_struct();
    // pass_array_of_size();
    // gcc_packed();
    // comma_notation();
    // no_return_func();
    function_pointer();
}