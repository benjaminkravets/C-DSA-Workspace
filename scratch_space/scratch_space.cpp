#include <cstddef>
#include <concepts>
#include <functional>
#include <string>
#include <vector>

#include <iostream>

using namespace std;

template <typename T>
class NumberFunctions
{
public:
    void add()
    {
        T &underlying = static_cast<T &>(*this);
        underlying.setValue(underlying.getValue() + 1);
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
    int getValue() { return value; }
    void setValue(int z) { value = z; }
};

// in CRTP, the inheritance clearly shows that the NumberFunctions interface is available vs having it in a header file
class Float : public NumberFunctions<Integer>
{
public:
    int value;
    Float(int z) : value(z) {}
    float getValue() { return value; }
    void setValue(float z) { value = z; }
};

int main()
{

    return 0;
}
