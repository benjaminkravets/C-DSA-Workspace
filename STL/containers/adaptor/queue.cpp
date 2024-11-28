#include <iostream>
#include <queue>

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

void queues()
{

    queue<int> queue_0;

    queue_0.push(22);
    queue_0.push(8);
    queue_0.push(52);
    queue_0.push(13);

    // queue_0 = 13 52 8 22
    // no iterators
    while (!queue_0.empty())
    {
        cout << queue_0.front() << endl;
        queue_0.pop();
    }
}

int main()
{
    queues();
    return 0;
}