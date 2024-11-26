#include <iostream>
#include <set>

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

void sets()
{

    set<int> set_0{3, 2, 1, 4};

    // will not insert the 1 since it's already there

    set_0.insert(1);

    print_for_loop(set_0);
}

void multi_sets()
{
    multiset<char> set_1 = {'a', 'd', 'c', 'b'};

    // will insert, duplicates allowed
    set_1.insert('b');

    print_for_loop(set_1);
}

int main()
{
    sets();
    multi_sets();
    return 0;
}