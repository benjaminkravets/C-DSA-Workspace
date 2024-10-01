#include <iostream>
using namespace std;

// member initializer
// https://stackoverflow.com/a/18811765

struct struct_0
{
    explicit struct_0(int i) : i(i) {} // x is initialized to 3.1416
    int i = 42;
    double x = 3.1416;
};

void member_initializer()
{
    struct_0 foo_0(1);
    cout << foo_0.i << " " << foo_0.x;
}

// get variable type
void get_variable_type(){
    double a = 1;
    int b = 1;
    cout << typeid(a).name() << endl;
    cout << typeid(b).name() << endl;

}




int main()
{
    //member_initializer();
    //get_variable_type();

    return 0;
}