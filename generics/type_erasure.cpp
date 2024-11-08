#include <iostream>

using namespace std;

// using this approach, there is now a common interface for all the signs assuming they inherit from the same base.

class Sign
{
public:
    virtual const char *shape() const = 0;
    virtual const char *action() const = 0;
};

class StopSign : public Sign
{
public:
    const char *shape() const { return "Octogon"; }
    const char *action() const { return "Stop"; }
};

class YieldSign : public Sign
{
public:
    const char *shape() const { return "Triangle"; }
    const char *action() const { return "Yield"; }
};

template <typename T>

void method_call(T *animal)
{
    cout << animal->shape() << endl;
    cout << animal->action() << endl;
}

void polymorphism_with_templates()
{

    Sign *signs[] = {new StopSign(), new YieldSign()};
    method_call(signs[0]);
    method_call(signs[1]);
}

// if a common interface is needed for types that don't inherit from the same base (although the signs do), a more complex setup is needed:

class SignConcept
{
public:
    virtual const char *shape() const = 0;
    virtual const char *action() const = 0;
};
class MyStopSign : public SignConcept
{
    StopSign StopSign_1;

public:
    const char *shape() const { return StopSign_1.shape(); }
    const char *action() const { return StopSign_1.action(); }
};

class MyYieldSign : public SignConcept
{
    YieldSign YieldSign_1;

public:
    const char *shape() const { return YieldSign_1.shape(); }
    const char *action() const { return YieldSign_1.action(); }
};

void interface_wrappers()
{

    SignConcept *signs[] = {new MyStopSign(), new MyYieldSign()};
    method_call(signs[0]);
    method_call(signs[1]);
}

// this works but now a wrapper class is needed for every concrete type. This can be improved by revisiting template polymorphism:

template <typename T>
class SignModel : public SignConcept
{
    const T *sign_0;

public:
    SignModel(const T *sign) : sign_0(sign) {}

    const char *shape() const { return sign_0->shape(); }
    const char *action() const { return sign_0->action(); }
};

void wrapper_template()
{
    SignConcept *signs[] = {new SignModel(new StopSign()), new SignModel(new YieldSign())};
    method_call(signs[0]);
    method_call(signs[1]);
}

// this can be hidden behind another class to remove interface complexity:
// https://davekilian.com/cpp-type-erasure.html

int main()
{
    // polymorphism_with_templates();
    // interface_wrappers();
    // wrapper_template();

    return 0;
}