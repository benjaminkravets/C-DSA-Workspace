#include <iostream>
using namespace std;

int add(int k, int l)
{
  return (k + l);
}

int invoke(int x, int y, int (*func)(int, int))
{
  return (func(x,y));
}

int main()
{
  int a = 1, b = 2;

  int c = invoke(a, b, &add);

  cout << c << endl;
}