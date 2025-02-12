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
    thread thread_1(add, 2, 2, &result);

    cout << result << endl;

    //spawn using a callable object
    car caravan;
    thread thread_2(caravan);


    //spawn using lambda
    auto f = [](int x) {
        for (int i = 0; i < x; i++){
            cout << "Lambda thread " << i << endl;
        }
    };

    thread thread_3(f, 5);

    thread_1.join();
    thread_2.join();
    thread_3.join();
}