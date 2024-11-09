#include <iostream>
#include <string>

using namespace std;

// rule of 0/3/5
// rule of 3 - (more common before c++ 11)- if the destructor, copy constructor, or copy assignment oeprators need explicitly declared, they probably all need to be.
// rule of 5 - same as rule of 3 but adding the move constructor and assignment operator, but if move operations are not defined they won't be generated, so copy operations will be used instead
// rule of 0 - prefer not define any special member functions when not needed, like when the class is a pure value type and consists only of pure values, or when resources maintained by the class are managed by smart pointers, file objects, etc.
class Car
{

    //the copy operations use const-correctness- the object being passed will not be modified

public:
    string model;
    int year;

    // Constructor
    Car(const string &model, int year) : model(model), year(year) {};
    // Copy constructor
    Car(const Car &prior) : model(prior.model), year(prior.year)
    {
        cout << "copy constructor" << endl;
    };
    // move constructor
    Car(Car &&prior) noexcept : model(move(prior.model)), year(prior.year)
    {
        prior.year = 0;
        cout << "move constructor" << endl;
    };
    // copy assignment
    Car &operator=(const Car &prior)
    {
        if (this != &prior)
        {
            // member initializer syntax won't be used because this is assignment, not construction
            model = prior.model;
            year = prior.year;
            cout << "copy assignment" << endl;
        }
        return *this;
    };
    // move assignment
    Car &operator=(Car &&prior)
    {
        if (this != &prior)
        {
            model = move(prior.model);
            year = prior.year;

            prior.year = 0;
            cout << "move assignment" << endl;
        }
        return *this;
    };
    // destructor
    ~Car() noexcept = default;
};

void constructing_assigning()
{
    Car car_0("g-wag", 2014); // use default constructor

    Car car_1 = car_0; // copy constructor

    Car car_2 = move(car_1); // move constructor

    car_2 = car_0; // copy assignment

    Car car_3{"bronco", 2022};
    Car car_4{"sonata", 2018};

    car_3 = move(car_4); // move assignment

}

int main()
{
    constructing_assigning();
    return 0;
}