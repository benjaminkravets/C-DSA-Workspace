#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>

using namespace std;

void func2(int& a){
   a++;
}

void func1(int& a){
   func2(a);
}

int main()
{
   int a = 1;

   func1(a);

   cout << a << endl;
   
}