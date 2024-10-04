#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>

using namespace std;
class A
{
   public:
   A()
   {
      cout << "A" << endl;
   }

};

class B : A
{
   public:
   B()
   {
      cout << "B" << endl;
   }

};

int main()
{
   int a[10] = {0};
   a[10] = 1;
}