#include <iostream>
using namespace std;

//1. member initializer
// https://stackoverflow.com/a/18811765
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


//2. get variable type
void get_variable_type()
{
    double a = 1;
    int b = 1;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;
}


//3. constructor chaining
class A_0
{
public:
    int x;
    A_0(int z)
    {
        x = z;
        cout << "called2" << endl;
    }
};

class B_0 : A_0
{
public:
    //calls base constructor before it's own
    B_0(int z) : A_0(z)
    {
        cout << "called" << endl;
    };
};


//4. aggregate initialization
class A_1{
    public:
    int a;
    int b;
    int c;
};

void aggregate_initialization(){
    struct A_1 A_1_instance = {1,2,3};
    cout << A_1_instance.a << " " << A_1_instance.b << " " << A_1_instance.c << endl;
}


//5. range-based for loop
void range_based_loop() {
    int x[5] = {1,2,3,4,5};
    for(auto a : x){
        cout << a << endl;
    }
}


//6. Virtual inheritance to solve the diamond problem
class A_1 {
public:
    A_1()                { cout << "A::A() "; }
    A_1(int x) : m_x(x)  { cout << "A::A(" << x << ") "; }
    int getX() const   { return m_x; }
private:
    int m_x = 42;
};

class B_1 : public A_1 {
public:
    B_1(int x):A_1(x)   { cout << "B::B(" << x << ") "; }
};

class C_1 : public A_1 {
public:
    C_1(int x):A_1(x) { cout << "C::C(" << x << ") "; }
};

class D_1 : public C_1, public B_1  {
public:
    D_1(int x, int y): C_1(x), B_1(y)   {
        cout << "D::D(" << x << ", " << y << ") "; }
};


int main()
{
    // member_initializer();
    // get_variable_type();
    //B_0 b(1);
    //aggregate_initialization();
    //range_based_loop();

    return 0;
}