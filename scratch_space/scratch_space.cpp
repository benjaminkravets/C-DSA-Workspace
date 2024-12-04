#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>
#include <array>
#include <queue>
#include <ranges>
#include <vector>
#include <iostream>

using namespace std;



template <typename T>
void foo(){
    cout << is_floating_point<T>::value << endl;
}

int main()
{
    metafunctions();
    foo<float>();

}