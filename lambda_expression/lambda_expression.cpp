//from https://www.scaler.com/topics/cpp/lambda-function-cpp/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <vector>
#include <math.h>

using std::cout;
using std::endl;
using std::vector;

int main()
{
    // vector of ints
    vector<int> numbers = {137, 171, 429, 467, 909};

    // visiting each element of nums and seperating prime numbers
    // using lambda expression
    for_each(numbers.begin(), numbers.end(), [](int x) mutable
             {
        bool notPrime = false;
        for(int i=2; i<=sqrt(x);i++){
            if(x%i==0){
                printf("%i is not prime \n", x);
                notPrime = true;
                break;
            } 
        }
        if(!notPrime){
            printf("%i is prime \n", x);
        }
         });

}

