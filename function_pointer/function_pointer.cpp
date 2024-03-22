#include <iostream>
using namespace std;

int add(int k, int l)
{
	return (k + l);
}

//pointer to an operator function is passed in along with its arguments
int call_operation(int x, int y, int (*func)(int, int))
{
	return (func(x,y));
}

int main()
{
	int a = 1, b = 2;

	//Call a math operator by passing arguments and an operator function pointer
	int c = call_operation(a, b, &add);

	cout << c << endl;
}