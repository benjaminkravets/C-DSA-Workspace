#include <iostream>

using namespace std;

class A
{
public:
    void SayHello() { cout << "Hello world" << endl; }
    // with 'virtual', calling a child class instance method through a base class pointer calls the correct (overridden) method, otherwise it calls the parent method.
    virtual void SayBye() { cout << "Goodbye world" << endl; }
};

class B : public A
{
public:
    void SayBye() { cout << "Goodbye, fairwell, and amen" << endl; }
};

int main()
{

    B b1;
    A &b_ptr = b1;

    b_ptr.SayBye();

    return 0;
}
