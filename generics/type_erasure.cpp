#include <iostream>

using namespace std;

// a common interface is needed for a few classes- this appraoch works for all the signs assuming they inherit from the same base.

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

class SpeedLimitSign
{
public:
    const char *shape() const { return "Square"; }
    const char *action() const { return "Speed Limit 55"; }
};

// since the signs are siblings with a common interface, each can be called in the same way:

void method_call_0(Sign *sign)
{
    cout << sign->shape() << endl;
    cout << sign->action() << endl;
}

// this can be templated to accomodate classes that don't inherit fron Sign but meet the interface requirements:
template <typename T>
void method_call_1(T *sign)
{
    cout << sign->shape() << endl;
    cout << sign->action() << endl;
}

void polymorphism_with_templates()
{

    Sign *signs[] = {new StopSign(), new YieldSign()};
    method_call_0(signs[0]);
    method_call_0(signs[1]);

    SpeedLimitSign *speed_limit_sign_0 = new SpeedLimitSign();
    method_call_1(signs[0]);
    method_call_1(signs[1]);
    method_call_1(speed_limit_sign_0);
}

// if a common interface is needed for types that don't inherit from the same base (although some signs do), a more complex setup is needed:

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

class MySpeedLimitSign : public SignConcept
{
    SpeedLimitSign SpeedLimitSign_1;

public:
    const char *shape() const { return SpeedLimitSign_1.shape(); }
    const char *action() const { return SpeedLimitSign_1.action(); }
};

void interface_wrappers()
{
    // now all the signs share an interface and can be put in the same array.
    SignConcept *signs[] = {new MyStopSign(), new MyYieldSign(), new MySpeedLimitSign()};

    method_call_1(signs[0]);
    method_call_1(signs[1]);
    method_call_1(signs[2]);
}

// this works but now a wrapper class is needed for every concrete type. This can be improved by revisiting template polymorphism:
// the sign concept is a concept of a sign shared amoung the concrete types.
// the sign model models the concrete types as instances of the concept
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
    SignConcept *signs[] = {new SignModel(new StopSign()), new SignModel(new YieldSign()), new SignModel(new SpeedLimitSign())};
    method_call_1(signs[0]);
    method_call_1(signs[1]);
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