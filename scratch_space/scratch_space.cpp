#include <iostream>
using namespace std;


auto adder (int here, int there) -> int {
    return here + there;
}


int main()
{

    cout << adder(1,2) << endl;

}
