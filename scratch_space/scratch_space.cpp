#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>
#include <array>
#include <parallel/algorithm>
#include <tuple>
#include <string>
#include <functional>

using namespace std;

void direct_constructor_uniform()
{
    int a = 1;
    int b(1);
    int c{1};
    
}  


int main()
{
    direct_constructor_uniform();
}