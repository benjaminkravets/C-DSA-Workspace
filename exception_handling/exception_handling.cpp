#include <iostream>
using namespace std;

void try_catch()
{
    int x = 5;

    try
    {
        if (x < 10)
        {
            throw x;
        }
    }

    catch (int x)
    {
        cout << "Exception caught where x = " << x << endl;
    }

    char a = 'z';

    try
    {
        if (a != 'b')
        {
            throw a;
        }
    }

    // won't catch 'z' beacuse it's not an int
    catch (int y)
    {
        cout << "Exception caught where a = " << a << endl;
    }

    catch (...)
    {
        cout << "Default exception" << endl;
    }
}

void throwing_function() //noexcept //will cause error
{
    //throw 1;
    int b = *((int *)0);

}

void function_throw()
{
    try
    {
        throwing_function();
    }
    catch (int a)
    {
        cout << "caught " << a << endl;
    }
}

int main()
{
    // try_catch();
    //function_throw();

}