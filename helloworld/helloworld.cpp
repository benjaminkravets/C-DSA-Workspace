#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;

int main()
{
    // list of number
    vector<int> numbers = {137, 171, 429, 467, 909};
    // list for prime numbers
    vector<int> v1 = {};
    
    // visiting each element of nums and seperating prime numbers
    // using lambda expression
    for_each(numbers.begin(), numbers.end(),[&v1](int x)mutable{
        bool notPrime = false;
        for(int i=2; i<=sqrt(x);i++){
            if(x%i==0){
                notPrime = true;
                break;
            } 
        }
        if(!notPrime) v1.push_back(x);
        });
    
    cout << "List of prime numbers" << endl;
        
    for(int i : v1){
        cout << i << " ";
    }
}