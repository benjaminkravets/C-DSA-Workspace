#include <iostream>
using namespace std;

// member initializer
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

int main()
{
    member_initializer();
    return 0;
}