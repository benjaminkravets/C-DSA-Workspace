#include <iostream>
#include <array>

using namespace std;

template <typename T>

void print_for_loop(T container)
{
    for (auto &a : container)
    {
        cout << a << " " << endl;
    }
    cout << endl;
}

// arrays are contiguous in memory with a fixed size, similar to C's arrays
void arrays()
{

    array<int, 5> array_0{1, 2, 3, 4, 5};
}

int main()
{
    arrays();
    return 0;
}