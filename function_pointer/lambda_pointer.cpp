#include <functional>
#include <iostream>
using namespace std;
 
//takes a lambda to define the operation
int call_operator(int a, int b, function<int(int,int)> oper){

    return oper(a,b);
}

int main()
{

    auto my_lambda = [](int a, int b) -> int {return a + b;};

    //a lambda can be passed as an argument
    int x = call_operator(1,1, my_lambda);

    cout << x << endl;
}