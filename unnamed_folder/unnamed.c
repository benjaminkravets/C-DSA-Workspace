#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>
#include <stdarg.h>

// 1. Many expressions values can share one statement
void cases_share_code()
{
    // after a case is matched, execution falls through until a break is reached.
    // 0 will execute 0 and 1, 2 will execute 2 and default
    int a = 2;

    switch (a)
    {
    case 0:
        printf("0\r\n");
    case 1:
        printf("1\r\n");
        break;
    case 2:
        printf("2 \r\n");

    default:
        printf("default \r\n");
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

void jump_to(int a)
{
    printf("fn1 called %i \r\n", a);
}

void function_pointer()
{
    // single function pointer:
    void *fn1_address = &jump_to;

    printf("fn1 at %p \n", fn1_address);

    void (*func_ptr)() = (void (*)())fn1_address;

    func_ptr(1);

    // jump table:

    void (*(jmp_table[3]))() = {&jump_to, &jump_to, &jump_to};

    jmp_table[0](2);
    jmp_table[1](3);
    jmp_table[2](4);
}

// 10. a compound literal exporession creates and initializes an unnamed object
struct shape
{
    char *color;
    int sides;
};

void print_struct(struct shape *foo)
{
    printf("%s \r\n", foo->color);
    printf("%i \r\n", foo->sides);
}
void compound_literals()
{
    struct shape bar = {"blue", 4};
    print_struct(&bar);
    // the compound literal (a type and initializer) are passed instead of a temporary struct
    print_struct(&(struct shape){.color = "red", .sides = 3});
}

// 11. designated intialization allows setting only certain elements of
// an array or members of a struct.

struct A_2
{
    int a;
    char b;
    int c;
};

void designated_initialization()
{
    int foo[5] = {[2] = 7, [4] = 5};
    // int foo[] = { [0 ... 9] = 1, [10 ... 30] = 2, [31] = 3 };

    for (int i = 0; i < 5; i++)
    {
        printf("%i ", foo[i]);
    }

    printf("\r\n");

    struct A_2 a = {.c = 1};

    printf("%i %c %i\r\n", a.a, a.b, a.c);
}
// 12. inline assembly
int add(int a, int b)
{
    asm("addl %1, %0" : "+r"(a) : "rm"(b));
    return a;
}

void inline_assembly()
{
    int foo = 1;
    asm("inc %[IncrementMe]" : [IncrementMe] "+r"(foo));
    printf("%i \r\n", add(1, 1));
}

// 13. vprintf and variadic funcitons

void use_vprintf(char *fmt, ...);
char fmt[] = "%s %s %s %s \n";

void use_vprintf(char *fmt, ...)
{
  va_list arg_ptr;
  //va_start accesses a variable arg list, gets arguments up to fmt- the last fixed variable
  va_start(arg_ptr, fmt);
  printf("%s \r\n", arg_ptr);
  //vprintf can be passed a variable number of strings like printf, but this can be passed as a va_list
  vprintf(fmt, arg_ptr);
  //resets ptr to null, must be called before return
  va_end(arg_ptr);

}

void pass_variadic() {
    use_vprintf(fmt, "Hello", "world", "Goodbye", "world");
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
    // function_pointer();
    // compound_literals();
    // designated_initialization();
    // inline_assembly();
    pass_variadic();
}