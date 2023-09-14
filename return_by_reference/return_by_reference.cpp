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
 
using namespace std;
 
// Driver code
int& fun()
{
    static int x = 10;
    //cout << x << endl;
    return x;
}
 
int main()
{
    fun() = 30;
    cout << fun();
    return 0;
}