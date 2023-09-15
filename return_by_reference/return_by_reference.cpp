#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>
using std::cout;
using std::endl;
using std::vector;
//From geeksforgeeks.com

int a = 2;

 
int& fun(int& b)
{
	b++;
    //may be acceptable since b is passed, a local var on the stack should not be returned
    return b;
}

int main()
{
    int& c = fun(a);
    //c is a referene to a after it has been incremented
    cout << c << endl;
    //original has been incremented;
    cout << a << endl;
}
