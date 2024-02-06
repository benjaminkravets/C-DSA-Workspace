#include <iostream>
#include <map>
 
using namespace std;

void print_map(map<auto, auto> cur_map){
    //map<auto, auto>::iterator start = cur_map.begin();
    auto start = cur_map.begin();
    
    while (start != cur_map.end()){
        cout << start->first << " " << start->second << endl;
        start++;
    }
    cout << endl;
}
 
int main()
{
    map<int, string> map_1;
    map_1[0] = "Greetings";
    map_1[1] = "from";
    map_1[2] = "California";
    
    map<string, int> map_2 = {{"Greetings", 0}, {"From", 1}, {"California", 2}};
    
    print_map(map_1);
    print_map(map_2);
    
    map<int, int> map_3;
    
    map_3.insert({1, 5});
    map_3.insert({2, 10});
    map_3.insert({3, 15});
    map_3.insert({4, 20});
    map_3.insert({5, 25});
    map_3.insert({6, 30});
    
    print_map(map_3);
    
    auto upper_index =  map_3.upper_bound(4);
    
    cout << upper_index->first << " " << upper_index->second << endl;
    
    int location_of_element = map_3.at(4);
    
    cout << location_of_element << endl;
    
    
}