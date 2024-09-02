#include <iostream>
using namespace std;



int main()
{

    int a = 2;
    int &b = a;
    int &c = b;

    cout << a << " " << b  << " " << c << endl;


    a++;

    cout << a << " " << b  << " " << c << endl;

}
