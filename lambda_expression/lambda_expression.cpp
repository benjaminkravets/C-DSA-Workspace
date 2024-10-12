// from https://www.scaler.com/topics/cpp/lambda-function-cpp/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <array>
#include <vector>
#include <math.h>

using namespace std;

void print(int a)
{
    cout << a << endl;
}

void lambda_for_each()
{
    vector<int> vector_0 = {132, 62, 97, 123, 21};

    for_each(vector_0.begin(), vector_0.end(), [](int &x)
             { x++; });

    for_each(vector_0.begin(), vector_0.end(), print);
}

void lambda_generate()
{
    // lambdas can have return value (although in this case the return type could be deduced automatically)
    list<int> list_0(5);

    int value = 1;

    generate(list_0.begin(), list_0.end(), [&value]() -> int
             { return value++; });

    for_each(list_0.begin(), list_0.end(), print);
}

void lambda_transform()
{
    list<int> list_1 = {10, 20, 30, 40, 50};
    list<int> list_2(5);

    transform(list_1.begin(), list_1.end(), list_2.begin(), [](int x)
              { return x * 2; });

    for_each(list_2.begin(), list_2.end(), print);
}

int main()
{
    // lambdas are inline, anonymous functors that are implemented as classes with an overloaded operator() const

    // lambda_for_each();
    // lambda_generate();
    // lambda_transform();
}
