#include <iostream>
#include <functional>
#include <memory>
using namespace std;

// 1. member initializer
//  https://stackoverflow.com/a/18811765
struct struct_0
{
    explicit struct_0(int i) : i(i) {} // x is initialized to 3.1416
    int i = 42;
    double x = 3.1416;
};

void member_initializer()
{
    struct_0 foo_0(1);
    cout << foo_0.i << " " << foo_0.x;
}

// 2. get variable type
void get_variable_type()
{
    double a = 1;
    int b = 1;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
}

// 3. constructor chaining and member initialization
class A_0
{
public:
    int x;
    A_0(int z)
    {
        x = z;
        cout << "A" << endl;
    }
};

class B_0 : A_0
{
public:
    int y;
    // calls base constructor before it's own, then using the same notation, initializes x
    B_0(int z) : A_0(z), y(z + 1)
    {
        cout << "B" << endl;
        cout << y << endl;
    };
};

// 4. aggregate initialization
class A_1
{
public:
    int a;
    int b;
    int c;
};

void aggregate_initialization()
{
    struct A_1 A_1_instance = {1, 2, 3};
    cout << A_1_instance.a << " " << A_1_instance.b << " " << A_1_instance.c << endl;
}

// 5. range-based for loop
void range_based_loop()
{
    int x[5] = {1, 2, 3, 4, 5};
    for (auto &a : x)
    {
        a++;
    };
    for (auto a : x)
    {
        cout << a << endl;
    }
}

// 6. Virtual inheritance to solve the diamond problem where the A constructor is called twice when a D is created. Try running this with and without the 'virtual' in B and C.
// https://stackoverflow.com/a/51343645
class A_2
{
public:
    A_2() { cout << "A::A() "; }
    A_2(int x) : m_x(x) { cout << "A::A(" << x << ") "; }
    int getX() const { return m_x; }

private:
    int m_x = 42;
};

class B_2 : virtual public A_2
{
public:
    B_2(int x) : A_2(x) { cout << "B::B(" << x << ") "; }
};

class C_2 : virtual public A_2
{
public:
    C_2(int x) : A_2(x) { cout << "C::C(" << x << ") "; }
};

class D_2 : public C_2, public B_2
{
public:
    D_2(int x, int y) : C_2(x), B_2(y)
    {
        cout << "D::D(" << x << ", " << y << ") ";
    }
};

// 7. trailing return type (used with lambdas).
auto max(int a, int b) -> int
{
    return a > b ? a : b;
}

// 8. using 'using'
class A_3
{
public:
    int y;
    A_3(int x) : y(x) { cout << "A_3" << endl; }
};

class B_3 : public A_3
{
public:
    // constructors are not inherited by default but can be accessed with 'using' (this brings in all constructors)
    using A_3::A_3;
};

void using_using()
{
    // using can act like typedef in c (it can be used for templates while typedef cannot)
    using u32 = uint32_t;
    // typedef uint32_t u32; //is equivalent
    u32 b = 2;

    B_3 d(1);
    cout << d.y << endl;
}

// 9. invoke and apply

void print_0(int a, int b)
{
    cout << a << " " << b << endl;
}
void print_1(tuple<int, int> a)
{
    cout << get<0>(a) << " " << get<1>(a) << endl;
}

void invoke_and_apply()
{
    // invoke takes any callable and calls it with provided args (callables include function pointer/reference, member function pointer, a class with (), or a pointer to member data)
    invoke(print_0, 1, 2);
    invoke(print_1, tuple(1, 2));
    // apply is similar but will pass a tuple's elements as the arguments
    apply(print_0, tuple(1, 2));
}

// 10. initialization syntax https://www.learncpp.com/cpp-tutorial/variable-assignment-and-initialization/
void default_copy_direct_uniform()
{
    /* default intitialization */
    int a;
    /* copy initialization/assignment */
    int b = 1;
    /* direct or member initialization/assignment (this syntax is still needed when class constructor arguments are needed like a vector length) */
    int c(1);
    /*uniform, aggregate, or list intialization allows many types (sets, maps, arrays, ints) to share a consistent syntax.
        this also prevents narrowing conversions and helps solve the most vexing parse issue
        (if compiler can't tell if a declaration is a function or object declation, it shooses function).
        This doesn't invoke copy constructor. Use this unless the surrounding code, adopted style, class or C++ version doesn't.
        */
    int d{1};
    /* same as d{1}*/
    int e = {1};
    /* zero (value) initialization */
    int f{};
}

// 11. SFINAE

template <typename T>
void f(T i, typename T::t *j) { std::cout << "1" << '\n'; }

template <typename T>
void f(T i, T j) { std::cout << "2" << '\n'; }

int SFINAE()
{
    // The compiler can use the 5 as an int in the first function but int::t* doesn't work, so (without erroring), it moves onto the next most viable function.
    // since there is a working candidate (the "2" one), the invocation is well-formed
    f(5, 7);
    return 0;
}

// 12. RAII

class MemoryBlock
{
private:
    char *data;
    int size;

public:
    MemoryBlock(int size) : size(size), data(new char[size])
    {
        cout << "Memory block created" << endl;
    }

    ~MemoryBlock()
    {
        cout << "Memory block deleted" << endl;

        delete[] data;
    }
};

// in RAII, the resource (handle) lifetime is tied to a class:
// resource allocation is done in constructor and resource deallocation is done in destructor.
// unique pointers do this automatically
void RAII()
{
    MemoryBlock block_0(20);
    unique_ptr<MemoryBlock> block_ptr_0 = make_unique<MemoryBlock>(20);
}

// 13. Metafunctions allow "named return values" at compile time and are
// used in remove_pointer and is_same. Constexpr members allow returning
// a value while typedefs allow returning a type.

template <int num>
struct plus_one
{
    static const int value = num + 1;
};

struct get_type
{
    typedef uint32_t u32;
};

void metafunctions()
{
    cout << plus_one<1>::value << endl;
    get_type::u32 x = 5;
    cout << x << endl;
}

// 14. Using constexpr
//  when a function is constexpr, calling it can result in a constant expression
//  can still be used at runtime if called with non-constant arguments
//  if compile time evaluation is required, use consteval
constexpr int multiplier(int a, int b)
{
    return a * b;
}

void using_constexpr()
{
    // const in a variable allows runtime initialization
    int a = 1;
    const int b = a;
    // constexpr variables must be initialized at compile time
    // this isn't allowed
    // constexpr int c = a;
    // this is allowed, the initialization value can be known at compile time.
    constexpr int d = 5;
    constexpr int e = d;

    // multiplier satisfies the constexpr requirement here
    constexpr int f = multiplier(1, 2);
}

// 15. statics in classes
class E
{
public:
    // class static variables are shared by all objects of a class
    static int z;

    // class static methods can be called without an object instance and
    // can only access static variables. the 'this' pointer can't be used.
    static int Afunction()
    {
        return z;
    }
};

// class static variables are initialized outside the class
int E::z = 3;

void class_statics()
{
    E x;
    cout << E::Afunction() << E::z << endl;
}

int main()
{
    // member_initializer();
    // get_variable_type();
    // B_0 b(1);
    // aggregate_initialization();
    // range_based_loop();
    // D_2 a(9, 1);
    // cout << max(3,1) << endl;
    // using_using();
    // invoke_and_apply();
    // default_copy_direct_uniform();
    // SFINAE();
    // RAII();
    // metafunctions();
    // using_constexpr();
    class_statics();
    return 0;
}