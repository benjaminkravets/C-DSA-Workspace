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

    // Pointer to the circle class
    circle *circle_ptr1 = new circle(1, "blue");
    cout << circle_ptr1->circumference() << endl;

    // A copy of the pointer can be made and the member data or methods accessed
    circle *circle_ptr2 = circle_ptr1;
    cout << circle_ptr2->circumference() << endl;

    // Such access could lead to atomicity issues from shared ownership, so we can make this property exclusive
    unique_ptr<circle> smart_circle_ptr1 = make_unique<circle>(2, "red");
    cout << smart_circle_ptr1->circumference() << endl;

    // Now if a second pointer is declared to point to the object, the other becomes invalid. (this can only done via move)
    unique_ptr<circle> smart_circle_ptr2 = move(smart_circle_ptr1);
    cout << smart_circle_ptr2->circumference() << endl;

    // This would cause a seg fault:
    // cout << smart_circle_ptr1->circumference() << endl;

    // the circle being pointed to will automatically be deleted when the unique_ptr is deleted or reassigned
}