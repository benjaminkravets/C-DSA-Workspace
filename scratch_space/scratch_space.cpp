#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>
#include <array>
#include <parallel/algorithm>

using namespace std;

int main()
{
    array<int, 5> v = {5, 2, 1, 8, 2};

    for (auto i : v) cout << i << " ";

    // ...

    // Explicitly force a call to parallel sort.
    __gnu_parallel::sort(v.begin(), v.end());

    for (auto i : v) cout << i << " ";


    return 0;
}