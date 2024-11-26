#include <iostream>
#include <vector>

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

void vectors()
{

    vector<int> vector_0{1, 2, 3};

    vector_0.push_back(5);

    print_for_loop(vector_0);

    vector_0.pop_back();

    print_for_loop(vector_0);

    vector_0.insert(vector_0.begin() + 1, 54);

    print_for_loop(vector_0);

}

int main()
{
    vectors();
    return 0;
}