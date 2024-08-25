#include <map>
#include <stdlib.h>
#include <iostream>


using namespace std;


int func_up() {
    int a = 1 + 1;
    return a;
}
 
int main()
{
 
    cout << func_up << " " << func_up << endl;
 
    return 0;
}