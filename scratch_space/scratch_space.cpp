#include <iostream>



auto adder (int here, int there) -> int {
    return here + there;
}


int main()
{

    std::cout << adder(1,2) << std::endl;

}
