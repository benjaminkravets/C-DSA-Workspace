#include <iostream>

using namespace std;

// static cast is most common, it does implicit conversions (int to float, pointer to void*, etc.)
// and can call explicit conversion functions. It relies only on information provided in the cast statement.
// It's not needed to cast an inheriting class instance to a base class
// but can be used to cast down (when virtual inheritiance isnt't involved).

void static_casting()
{
    int a = 1;
    double b = static_cast<double>(a);
}

class A
{
public:
    virtual void test() {}
};
class B : A
{
};

// dynamic_cast casts a polymorphic class pointer/reference to another polymorphic class pointer/reference
// up/down/sideways in an inheritane hierarchy (except when there are multiple objects of the same
// type in a hierarchy (diamond) and virtual inheritance isn't used). Performs run-time checks and is safer.

void dynamic_casting()
{
    A *a = new A();
    B *b = dynamic_cast<B *>(a);
}
// const_cast can add or remove constness (or volatileness) from pointers/references that point to a (non-const) variable.
// It is mostly for compatibility with older interfaces

void const_casting()
{
    int a = 1;
    const int *b = &a;

    //*b += 1; //doesn't work
    (*const_cast<int *>(b))++;

    cout << a << endl;
}

// ths most dangerous, turning one type into another. The only guarantee is that normally, if
// a variable is cast to another type and cast back to the original type (assuming the intermediate type
// wasn't smaller than the original), it's value will be the same.

class C
{
};

void func_0()
{
    cout << "hi" << endl;
}
void reinterpret_casting()
{
    void (*a)() = func_0;
    reinterpret_cast<C *>(a);
    reinterpret_cast<void (*) ()>(a);
    a();
}

int main()
{
    static_casting();
    dynamic_casting();
    const_casting();
    reinterpret_casting();

    return 0;
}