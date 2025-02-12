#include <concepts>
#include <iostream>
using namespace std;

// concepts are a set of constraints on template parameters evaluated at compile time.
template <typename T>
concept Number = integral<T> || floating_point<T>;

// T must obey the constraints of Number
template <Number T>
class A
{
    T a;

public:
    A(T z) : a(z) { cout << "A is used" << endl; }
};

template <typename T>
// requires expression- define what is required
concept Duck = requires(T v) {
    // requires int member eggs
    { v.eggs } -> convertible_to<int>;

    // requires method quack which returns an int
    { v.quack() } -> std::convertible_to<int>;
};

template <typename T>
// requires clause- use an expression to enforce requirements
    requires integral<T>
T increment(T z)
{
    return z + 1;
}

class Mallard
{
public:
    int eggs;
    int quack()
    {
        cout << eggs << endl;
        return eggs;
    }
};

int main()
{
    // works
    A(1.1);
    // doesn't work
    // A("hi");

    // see if B meets the HasIntA and ReturnsInt concepts
    static_assert(Duck<Mallard>);

    // works
    int a = 2;
    cout << increment(a) << endl;
    // doesn't work
    // auto b = {1, 2, 3};
    // cout << increment(b) << endl;

    return 0;
}