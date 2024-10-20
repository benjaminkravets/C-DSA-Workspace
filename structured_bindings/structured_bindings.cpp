#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>
#include <array>
#include <parallel/algorithm>
#include <tuple>
#include <string>

using namespace std;

class A
{
public:
    int a;
    int b;
    int c;
};

void structured_bindings()
{
    A a = {1, 2, 3};

    // this syntax works on tuples, arrays, structs
    auto [b, c, d] = a;
    cout << b << " " << c << " " << d << " " << endl;

    pair<char, int> e('a', 1);

    auto [f, g] = e;
    cout << f << " " << g << endl;
}

// tuples are useful to return or pass multiple values or as a "generic struct"
void tuples()
{
    tuple a(1.234, "five", 6);

    // while structured bindings are preffered, get and tie are available
    auto [b, c, d] = a;

    cout << b << " " << c << " " << d << endl;

    cout << get<0>(a) << " " << get<1>(a) << " " << get<2>(a) << endl;

    double e;
    string f;
    int g;

    tie(e, f, g) = a;

    cout << e << " " << f << " " << g << endl;
}

int main()
{
    structured_bindings();
    //tuples();
}