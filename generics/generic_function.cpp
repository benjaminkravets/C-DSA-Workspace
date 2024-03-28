#include <iostream>
using namespace std;


//generic function to compare two variables of an unknown type
template <typename T>

T least(T a, T b){
    return (a < b) ? a : b;
}

int main(){

    cout << least(13.3, 19.0) << endl;

    cout << least('z', 'r') << endl;

}