#include <iostream>
#include <utility>
#include <tuple>
using namespace std;
 

int main()
{
    pair<int, int> pair_1 = {3, 7};
    int x, y;
    tie(x, y) = pair_1;
    
    cout << x << y << endl;
    
    pair pair_2 = {4, 9};
    
    cout << pair_2.first << pair_2.second << endl;
    
    pair_1.swap(pair_2);
    
    cout << pair_1.first << pair_1.second << endl;
}