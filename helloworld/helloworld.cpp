//derived from geeksforgeeks.com
#include <iostream>
#include <vector>

using namespace std;

void fun(char* arr)
{
    int i;
    unsigned int n = strlen(arr);
    cout << "n = " << n << endl;
    for (i = 0; i < n; i++)
        cout << arr[i] << " ";
}
 
// Driver program
int main()
{
    char arr[] = "geeksquiz";
    fun(arr);
    return 0;
}