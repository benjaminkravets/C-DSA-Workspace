// derived from geeksforgeeks.com
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include <regex>
using namespace std;

int main()
{
  
    typedef int arr[3];
  
    // Making new 1D array
  
    arr array1{ 1 , 1, 1};
      
  
    cout << "Array output: "
         << "\n";
    for (int i = 0; i < 3; i++) {
        cout << array1[i] << " ";
    }
    cout << "\n";
  
    // Making new 2D array
    // Matrix is an array of arrays with size
    // ( 3 X 3 )
    arr matrix[3];
  
    cout << "Matrix output: "
         << "\n";
  
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            // Initializing the matrix
            matrix[i][j] = i * j;
        }
    }
  
    // Outputting the matrix
  
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 3; j++) {
            cout << matrix[i][j] << "  ";
        }
        cout << "\n";
    }
  
    return 0;
}