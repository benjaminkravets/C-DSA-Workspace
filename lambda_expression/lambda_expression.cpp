// from https://www.scaler.com/topics/cpp/lambda-function-cpp/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <vector>
#include <math.h>

using std::cout;
using std::endl;
using std::vector;

void print(int a)
{
    cout << a << endl;
}

int main()
{
    // vector of ints
    vector<int> numbers = {137, 171, 429, 467, 909};

    // lambdas are anonymous functors
    for_each(numbers.begin(), numbers.end(), [](int &x)
             {
                 x++;
             });

    for_each(numbers.begin(), numbers.end(), print);
}
