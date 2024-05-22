#include <iostream>

using namespace std;

class Transmission
{
private:
    int gear;

public:
    void shift_to_gear(int a)
    {
        gear = a;
        cout << "Gear shifted to " << a << endl;
    }
};

class Tire
{
public:
    double psi;

public:
    void fill_tires(double b)
    {
        psi = b;
        cout << "Tires filled to " << b << " PSI" << endl;
    }
};

// the Car class is formed by inheriting from the Transmission and Tires classes (inheritance implies an "is a relationship")
class Car : public Transmission, public Tire
{
};

// the Truck class is formed by composing from the Transmission and Tire classes-
// the class will get an instance and therefore access to the methods of each and can add a wrapper around them
// providing a "has a" relationship.

class Truck
{
private:
    Transmission transmission;
    Tire tire;

public:
    void shift_to_gear(int a)
    {
        transmission.shift_to_gear(a);
    }
    void fill_tires(int b)
    {
        tire.fill_tires(b);
    }
};

int main()
{
    Car my_car;
    my_car.shift_to_gear(2);
    my_car.fill_tires(40);
}