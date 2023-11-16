#include <iostream>
#include <string.h>
using namespace std;
 
struct Base {
public:
    int x;
};
 
// is equivalent to
// struct Derived : public Base {}
struct Derived : Base {
public:
    int y;
};
 
int main()
{
    Derived d;
 
    // Works fine because inheritance
    // is public.
    d.x = 20;
    cout << d.x;
    cin.get();
    return 0;
}