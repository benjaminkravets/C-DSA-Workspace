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


    //Two weak poiners can share non owning access to the same object- with no uniqueness or ownership, 
    //what makes weak pointers special is there knowledge that the object they point to is not deallocated 
    //dangling memory.

    shared_ptr<circle> smart_circle_ptr1(new circle(3.2, "cyan"));

    //Must be created by converting from a shared ptr.
    weak_ptr<circle> smart_circle_ptr2(smart_circle_ptr1);
    weak_ptr<circle> smart_circle_ptr3 = smart_circle_ptr2;

    //Count will still be 0 even after creating copy
    cout << smart_circle_ptr2.use_count() << endl;


}