#include <iostream>
#include <vector>

using namespace std;


void range_based_loop(){
    vector<int> a = {1, 2, 3, 4, 5};


    //visit elements values (inefficient, calls copy constructor. use const reference instead (see below))
    for(auto x : a){
        cout << x << ' ';
    }

    cout << endl;

    //modify element values (by reference)
    for(auto &x : a){
        x++;
    }


    for(const auto& x : a){
        cout << x << ' ';
    }
    cout << endl;
}


int main()
{
    range_based_loop();
}