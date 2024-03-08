
#include <tuple> 
#include <iostream>
#include <stdio.h>
using namespace std; 
  
// Creating a structure named Point 
struct Point 
{ 
    int x, y; 
      
    // Default Constructor 
    Point() : x(0), y(0)  
    { 

          
    } 


      
    // Parameterized Constructor for Init List 
    Point(int x, int y) : x(x), y(y)  
    { 
        cout << x << " " << y << endl;
    } 
    auto operator()() 
    { 
        // returns a tuple to make it work with std::tie 
        return make_tuple(x, y);  
    } 
}; 
  
// Driver code 
int main() 
{ 
    Point p = {1, 2}; 
    int x_coord, y_coord; 
    tie(x_coord, y_coord) = p(); 
      
    cout << "X Coordinate : " << x_coord << endl; 
    cout << "Y Coordinate : " << y_coord << endl; 
      
    return 0; 
} 