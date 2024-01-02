

#include <algorithm>
#include <iostream>
using namespace std;

class Test {
public:
    virtual ~Test() = 0;
    // Test now becomes abstract class
};
Test::~Test() {}

class Tested : public Test {
    public:
    ~Tested() {}
};
 
// Driver Code
int main()
{
    Tested p;
    Tested* t1 = new Tested;
    return 0;
}