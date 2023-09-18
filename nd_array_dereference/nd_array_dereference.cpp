//derived from geeksforgeeks.com
#include <iostream>
#include <vector>

using namespace std;

const int l = 4;

int main()
{
    int arr2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};
    
    cout << arr2[1][3] << endl;
    cout << *(*(arr2+1)+3) << endl;

    int arr3[2][3][2] = { {{1, 2}, {3, 4}, {5, 6}}, {{7, 8}, {9, 10}, {11, 12}} };

    cout << arr3[1][1][0] << endl;
    cout << *(*(*(arr3+1)+1))+0 << endl;
}