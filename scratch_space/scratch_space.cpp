

#include <iostream>
using namespace std;
 
 void swap(int& x, int& y)
{
    int temp = x;
    x = y;
    y = temp;
};

int main()
{
    int a = 1;
    int& b = a;


    cout << a << endl;
    
    b = 2;

    cout << a << endl;


}