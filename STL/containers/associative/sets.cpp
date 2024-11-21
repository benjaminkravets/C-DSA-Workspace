#include <iostream>
#include <iterator>
#include <set>
 
using namespace std;
 
int main()
{

    //multiset is like set but can contain duplicates
    multiset<int> int_multiset;
 
    int_multiset.insert(7);
    int_multiset.insert(1);
    int_multiset.insert(4);
    int_multiset.insert(2);
    int_multiset.insert(10);
    int_multiset.insert(20);
 
    int_multiset.insert(7);
    int_multiset.insert(1);
 
    for (set<int>::iterator itr = int_multiset.begin(); itr != int_multiset.end(); ++itr)
    {
        cout << *itr << endl;
    }
    
    cout << endl;
    
    for (set<int>::iterator itr = int_multiset.lower_bound(4); itr != int_multiset.upper_bound(10); ++itr)
    {
        cout << *itr << endl;
    }
 
 
    return 0;
}