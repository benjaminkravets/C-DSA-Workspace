#include <iostream>
#include <algorithm>
#include <array>
#include <tuple>
#include <array>
#include <queue>
#include <ranges>
#include <vector>

using namespace std;

//https://learn.microsoft.com/en-us/cpp/standard-library/ranges?view=msvc-170#views

void using_iterators()
{
    vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10}, intermediate, output;

    copy_if(input.begin(), input.end(), back_inserter(intermediate), [](int i)
            { return i % 3 == 0; });
    transform(intermediate.begin(), intermediate.end(), back_inserter(output), [](int i)
              { return i * i; });

    for (auto i : output)
    {

        cout << i << endl;
    }
}
// the ranges header functions do operate on ranges without explicitly passing the begin and iterator
void using_ranges()
{
    vector<int> input{0, 10, 1, 9, 2, 8, 3, 7, 4, 6, 5};

    ranges::sort(input);

    for (auto i : input)
    {
        cout << i << endl;
    }
}


// views provide a non-owning way of interpreting a range, removing the need for an intermediate value at each filter/transform/sort step
void using_views()
{
    vector<int> input{0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    auto output = input | views::filter([](int i)
                                        { return i % 3 == 0; }) |
                  views::transform([](int i)
                                   { return i * i; });

    for (auto i : output)
    {
        cout << i << endl;
    }
}

int main()
{
    using_iterators();
    using_views();

    return 0;
}