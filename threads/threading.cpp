#include <thread>
#include <iostream>

using namespace std;

void add(int a, int b, int* result){
    cout << "Adding" << endl;
    *result = a + b;
}

class car {

    public:

    void operator () (){
        cout << "Car object called" << endl;
    }
};

int main(){

    //spawn using a function
    int result;
    std::thread thread_1(add, 2, 2, &result);
    thread_1.join();
    cout << result << endl;

    //spawn using a callable object
    car caravan;
    std::thread thread_2(caravan);
    thread_2.join();

    

}