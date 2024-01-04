#include <iostream>
using namespace std;

int main(){

    int x = 5;

    try {
        if (x < 10){
            throw x;
        }
    }

    catch(int x){
        cout << "Exception caught where x = " << x << endl;
    }

    char a = 'z';

    try {
        if (a != 'b'){
            throw a;
        }
    }

    catch(int y){
        cout << "Exception caught where a = " << a << endl;
    }

    catch(...){
        cout << "Exception caught here since no other catch statements were reached" << endl;
    }
}