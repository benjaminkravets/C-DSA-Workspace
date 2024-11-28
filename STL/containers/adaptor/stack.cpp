#include <iostream>
#include <stack>

using namespace std;

void stacks()
{

    stack<int> stack_0;
    stack_0.push(1);
    stack_0.push(22);
    stack_0.push(3);
    stack_0.push(4);

    // data isn't accessible by iterator

    while (!stack_0.empty())
    {
        cout << stack_0.top() << " " << endl;
        stack_0.pop();
    }
}

int main()
{
    stacks();
    return 0;
}