#include <iostream>
#include <memory>

using namespace std;

class circle
{
    int radius;
    string color;

public:
    circle(int r, string c)
    {
        radius = r;
        color = c;
    }

    double circumference()
    {
        return 2 * 3.14159 * radius;
    }
};

int main()
{
    
    // classical pointers don't know if their referenced data is deallocated or not
    circle *circle_ptr_0 = new circle(1, "red");
    circle *circle_ptr_1 = circle_ptr_0;
    delete circle_ptr_0; // now circle_ptr_0 points to undefined data

    // start with a shared_ptr (weak)
    shared_ptr<circle> circle_ptr_2(new circle(1, "teal"));

    // get weak pointer to data without taking ownership (count will not increase)
    weak_ptr<circle> circle_ptr_3 = circle_ptr_2;

    // weak_ptrs cannot access data directly, but .lock can get a shared pointer that can.
    // cout << circle_ptr_3.lock()->circumference() << endl;

    // expried will tell if object pointed to is deleted (count == 0). weak pointers are not for creating,
    cout << circle_ptr_3.expired() << endl;

    // reset "deletes" a pointer (can be assigned new value by argument)
    circle_ptr_2.reset();

    cout << circle_ptr_3.expired() << endl;
}