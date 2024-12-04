#include <iostream>


using namespace std;

template <typename T>
void print(T arr[], int size)
{
    cout << "General function" << endl;
}

//full specialization for char type
template <>
void print<char>(char arr[], int size)
{
    cout << "Specialized function" << endl;
}

template <typename T>
class A
{
public:
    A(T z)
    {
        cout << "General class" << z << endl;
    }
};

//full specialization for int type
template <>
class A<int>
{
public:
    A(int z)
    {
        cout << "Specialized class" << z << endl;
    }
};

void template_specialization()
{
    int a[10] = {0};

    print(a, 10);

    char b[10] = {0};

    print(b, 10);

    A a_0('c');

    A a_1(1);
}

// partial template specialization (only for classes; use overloading for a similar outcome in functions)
template <typename T, typename U> // <typename T... is the template parameter list (full specialization doesn't have this)
class X
{
    public:
    X(T t, U u){
        cout << "General template" << endl;
    }
};

template <typename T>
class X<T, int> //this is a template argument list, needs to satisfy the parameter list of the original class
{
    public:
    X(T t, int u){
        cout << "Partially specialized template" << endl;
    }
};

void template_partial_specialization()
{
    X<char, char> x_0('c', 'c');

    X<char, int> x_1('c', 1);
    cout << "here" << endl;
}

int main()
{
    template_specialization();
    template_partial_specialization();

    return 0;
}