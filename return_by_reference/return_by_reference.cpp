#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <vector>
#include <string>

using namespace std;

class A
{
    int b;
    public:

    A(int i) : b(i){};

    int &get()
    {
        return b;
    }
};



int main()
{
    A A_instance(2);

    //A_instance.get() = 4; //would set the value of b

    cout << A_instance.get() << endl;

    return 0;
}
