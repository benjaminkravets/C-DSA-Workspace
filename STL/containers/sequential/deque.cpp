#include <iostream>
#include <deque>

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

void deques()
{

    deque<int> deque_0{1, 2, 3};

    deque_0.push_back(5);

    print_for_loop(deque_0);

    deque_0.pop_back();

    print_for_loop(deque_0);

    deque_0.push_front(7);

    print_for_loop(deque_0);

}

int main()
{
    deques();
    return 0;
}