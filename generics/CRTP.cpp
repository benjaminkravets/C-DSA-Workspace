#include <cstddef>
#include <concepts>
#include <functional>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// https://www.fluentcpp.com/2017/05/16/what-the-crtp-brings-to-code/

// in CRTP, rather than the base class being the interface and the derived class the implementation,
//  the derived class offers an interface to the base class.

// CRTP struct factors out static_cast
template <typename T>
struct CRTP
{
public:
    T &underlying() { return static_cast<T &>(*this); }
    T const &underlying() const { return static_cast<T const &>(*this); }
};

template <typename T>
class NumberFunctions : public CRTP<T>
{
public:
    void add()
    {
        this->underlying().setValue(this->underlying().getValue() + 1);
    }
    void subtract()
    {
        this->underlying().setValue(this->underlying().getValue() - 1);
    }
};

// Rather than Integer being in a "is a" relationship with NumberFunctions, NumberFunctions is only adding functionality
class Integer : public NumberFunctions<Integer>
{
public:
    int value;
    Integer(int z) : value(z) {}
    void factor() {}
    int getValue() { return value; }
    void setValue(int z) { value = z; }
};

// CRTP is more readable, the inheritance clearly shows that the NumberFunctions interface is available vs having it in a header file
// Float (and Integer) are guaranteed to work with NumberFunctions
class Float : public NumberFunctions<Float>
{
public:
    float value;
    Float(float z) : value(z) {}
    void round() {}
    float getValue() { return value; }
    void setValue(float z) { value = z; }
};

// less often, CRTP can also be used for static interfaces, returning to the base-interface derived-implementation ordering.

template <typename T>
class Amount
{
public:
    double getValue() const
    {
        return static_cast<T const &>(*this).getValue();
    }
};

class ConstantAmount : public Amount<ConstantAmount>
{
public:
    double getValue() const { return 1; };
};

class VariableAmount : public Amount<VariableAmount>
{
public:
    explicit VariableAmount(int x) : value(x) {}
    double getValue() const { return value; };

private:
    int value;
};

// Using CRTP for static interfaces avoids vtables, concepts are often better.

int main()
{
    ConstantAmount c1;
    cout << c1.getValue() << endl;
    VariableAmount v1(2);
    cout << v1.getValue() << endl;

    return 0;
}
