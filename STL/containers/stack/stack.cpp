#include <iostream> 
#include <stack>

using namespace std;

int main() {
    
    stack<float> stack;
    
    stack.push(1.2);
    stack.push(6.78);
    stack.push(-3.4);
    stack.push(2.79);

   
    while (stack.empty() == 0) {
        cout << stack.top() << endl;
        stack.pop();
    }
    
}