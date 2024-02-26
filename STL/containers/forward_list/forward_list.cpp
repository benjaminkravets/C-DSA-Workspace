#include <forward_list>
#include <iostream>
using namespace std;


void show_list(forward_list<auto> cur_list){
    
    for(auto& itr : cur_list){
        cout << itr << " ";
    } 
    cout << endl;
}

int main()
{
    
    //declare list using assign
    forward_list<int> list1;
    
    list1.assign({1,2,3,4,5,6,7});
    
    show_list(list1);
    
    
    //copy list using assign
    forward_list<int> list2;
    
    list2.assign(list1.begin(), list1.end());
    
    show_list(list2);
    
    
    //remove values over 4
    list2.remove_if([](int x) {return x > 4;});
    
    show_list(list2);
    
    
    //spice list onto list 1
    list1.splice_after(list1.before_begin(), list2);
    
    show_list(list2);
    show_list(list1);
    
    
    return 0;
}