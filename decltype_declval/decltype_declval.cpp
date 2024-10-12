#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>

using namespace std;

//decltype can deduce the return of a function (even when it is required that the argument names be in scope). declval may also work around this issue.
template <class T, class U>
auto mul(T x, U y) -> decltype(x * y)
{
    return x * y;
}

int add(int x, int y)
{
    return x + y;
}

class A
{
public:
    int print()
    {
        return 1;
    }
};

void decltype_declval()
{
    // decltype takes an expression or variable and gives the declared type of it.
    // The auto keyword works on types, decltype works on expressions- decltype works with references, auto by itself does not
    int a = 1;
    decltype(a) b;

    // c is an int& to a
    decltype((b)) c = a;

    // d is an integer
    decltype(add(1, 1)) d = 2;

    // declval returns rvalue reference to whatever it's passed.
    // handy for when an object (like A) isn't available- can be thought of as returning an rvalue reference to a fake instance.
    // should be used where nothing is/would be executed.
    decltype(declval<A>().print()) e = 1;

    A a_0;
    decltype(a_0.print()) z = 1;
}

int main()
{
    decltype_declval();
}