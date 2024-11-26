#include <iostream>
#include <map>

using namespace std;

template <typename T>

void print_for_loop(T container)
{
    for (auto &a : container)
    {
        cout << a.first << " " << a.second << " " << endl;
    }
    cout << endl;
}

void maps()
{

    map<int, char> map_0 = {{1, 'a'}, {3, 'c'}};

    map_0.emplace(2, 'b');

    map_0.insert(pair<int, char>{4, 'd'});

    // won't be added, not unique
    map_0.emplace(1, 'z');

    print_for_loop(map_0);
}

void multi_maps()
{
    multimap<char, double> map_1 = {{'a', 1.234}, {'c', 3.456}};

    map_1.emplace('b', 2.345);

    map_1.insert(pair<char, double>{'d', 4.567});

    // will be added
    map_1.emplace('a', 5.678);

    print_for_loop(map_1);
}

int main()
{
    maps();
    multi_maps();
    return 0;
}