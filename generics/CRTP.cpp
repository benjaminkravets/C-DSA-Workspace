#include <cstddef>
#include <concepts>
#include <functional>
#include <string>
#include <vector>
#include <iostream>

using namespace std;

// in CRTP, rather than the base class being the interface and the derived class the implementation,
//  the derived class offers an interface to the base class.

template <typename T>
class NumberFunctions
{
public:
    void add()
    {
        T &underlying = static_cast<T &>(*this);
        underlying.getValue(underlying.getValue() + 1);
    }
    void subtract()
    {
        T &underlying = static_cast<T &>(*this);
        underlying.setValue(underlying.getValue() - 1);
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

// in CRTP, the inheritance clearly shows that the NumberFunctions interface is available vs having it in a header file
// Float (and Integer) are guarunteed to work with NumberFunctions
class Float : public NumberFunctions<Float>
{
public:
    int value;
    Float(int z) : value(z) {}
    void round() {}
    float getValue() { return value; }
    void setValue(float z) { value = z; }
};

// CRTP can also be used for static interfaces, returning to the base-interface derived-implementation ordering.

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
