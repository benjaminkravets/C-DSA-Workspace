#include <iostream>
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

// 7. trailing return type
auto max(int a, int b) -> int
{
    return a > b ? a : b;
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

    return 0;
}