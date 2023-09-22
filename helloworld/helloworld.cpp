// derived from geeksforgeeks.com
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include <regex>
using namespace std;

struct Cpp_Struct
{
  public:
    const int i;
    int k;
    Cpp_Struct():i(2),k(3){}
};
int main()
{
    Cpp_Struct obj1;
    cout << "Struct with constant members: " << obj1.i << " " << obj1.k << endl;
    return 0;
}