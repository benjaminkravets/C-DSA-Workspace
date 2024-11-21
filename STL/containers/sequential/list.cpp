#include <iostream>
#include <list>
#include <forward_list>

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

// often individual elements are (doubly) linked to each other by pointers- they can be resized, appended to, or deleted from
void lists()
{

    list<int> list_0{1, 2, 3};

    list_0.push_back(5);

    print_for_loop(list_0);

    list_0.pop_back();

    print_for_loop(list_0);

    for(auto i = list_0.rbegin(); i != list_0.rend(); i++){
        cout << *i << endl;
    }

    cout << endl;
}

void forward_lists()
{
    forward_list<int> forward_list_0{1, 2, 3, 4, 5};
    

    for(auto i = forward_list_0.begin(); i != forward_list_0.end(); i++){
        cout << *i << endl;
    }

    // reverse iteration doesn't work
    // for(auto i = forward_list_0.rbegin(); i != forward_list_0.rend(); i++){
    //     cout << *i << endl;
    // }
}

int main()
{
    lists();
    forward_lists();
    return 0;
}