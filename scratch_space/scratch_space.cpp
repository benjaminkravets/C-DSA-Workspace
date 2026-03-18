#include <cstddef>
#include <concepts>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <type_traits>
#include <iostream>
#include <string>

#include <iostream>
using namespace std;

class Base {
public:
    virtual void greet() {
        cout << "Hello from Base!" << endl;
    }
};

class Greeter : public Base {
public:
    void sayHi(const char* str) {
        cout << "Greeter says: " << str << endl;
    }
    void greet() override {
        cout << "Hello from Greeter!" << endl;
    }
};

class Executor : public Base {
public:
    void exec(const char* cmd) {
        system(cmd);  // Dangerous: executes command on system shell
    }
    void greet() override {
        cout << "Hello from Executor!" << endl;
    }
};
#include <compare>
class Point {
    int x;
    int y;
    auto operator<=>(const Point& other) const = default;
};

int main() {
    // Base* b1 = new Greeter();
    // Base* b2 = new Executor();

    // Greeter* g;

    // // Correct cast - using Greeter object as Greeter
    // g = static_cast<Greeter*>(b1);
    // g->sayHi("This is safe.");  // prints message safely

    // // Incorrect cast - treating Executor as Greeter
    // g = static_cast<Greeter*>(b2);
    // g->sayHi("calc.exe");  // Actually calls Executor::exec (unexpected)

    // delete b1;
    // delete b2;
    // return 0;

}

