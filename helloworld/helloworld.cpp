#include <iostream>
#include <list>
#include <vector>
using std::cout;

int main()
{
    std::vector<int> v = {1, 2, 3, 4, 5};
    for (std::vector<int>::iterator it = v.begin();
         it != v.end(); it++)
    {
        cout << *it << "\t";
    }
    return 0;
}
