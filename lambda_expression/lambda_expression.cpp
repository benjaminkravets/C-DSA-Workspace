//derived from https://www.scaler.com/topics/cpp/lambda-function-cpp/
#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <vector>
using std::cout;
using std::endl;
using std::vector;
/*
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
                break;
            } 
        } });

}*/

void abssort(float* x, unsigned n) {
    std::sort(x, x + n,
        // Lambda expression begins
        [](float a, float b) {
            return (std::abs(a) < std::abs(b));
        } // end of lambda expression
    );
}

int main(){
    float r = .5;
    abssort(&r, 4);
}