#include <iostream> 
#include <unordered_map> 
using namespace std; 



int main() {

  //Direct insertion
  unordered_map<string, int> my_map = {{"Escape", 2}, {"Monte Carlo", 1}, {"Caravan", 5}};

  for(auto x : my_map){
    cout << x.first << " " << x.second << endl;
  }
  //Addressing operator insertion
  my_map["Ranger"] = 13;
  my_map["Explorer"] = 7;

  cout << endl;

  for(auto x : my_map){
    cout << x.first << " " << x.second << endl;
  }

  //insertion function
  my_map.insert(make_pair("Model 3", 15));

  cout << endl;

  for(auto x : my_map){
    cout << x.first << " " << x.second << endl;
  }

  //Find a key in the map
  if (my_map.find("Model 3") != my_map.end())
    cout << "Found " << "Model 3" << endl;

  if (my_map.empty() == 1)
    cout << "my_map has no pairs" << endl;

  unordered_map<string, int>::iterator itr = my_map.find("Escape");

  my_map.erase("Escape");

  cout << endl;

  for(auto x : my_map){
    cout << x.first << " " << x.second << endl;
  }

  return 0;
}