#include <iostream>
#include <memory>

using namespace std;
 

class circle {
    int radius;
    string color;

    public:
    circle(int r, string c){
        radius = r;
        color = c;
    }

    double circumference(){
        return 2 * 3.14159 * radius;
    }

};

int main(){

    //The shared is similar to a normal pointer but it still has ownership and will count how many shared pointers there are
    shared_ptr<circle> smart_circle_ptr1(new circle(4,"teal"));
    cout << smart_circle_ptr1->circumference() << endl;

    //When a copy is made, ownership is shared, so both pointers can now be used to access the object.
    shared_ptr<circle> smart_circle_ptr2 = smart_circle_ptr1;
    cout << smart_circle_ptr2->circumference() << endl;
    cout << smart_circle_ptr1->circumference() << endl;

    //To confirm multiple owners the count can be accessed
    cout << smart_circle_ptr1.use_count() << endl;

    //when all pointers to the shared object are deleted (out of scope) or pointed to other objects (use count is 0), object will be automatically deleted

}