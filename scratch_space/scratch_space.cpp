

#include <iostream>
using namespace std;

// class Singleton
// {
// public:
//     static Singleton *GetInstance()
//     {
//         if (instance_ == NULL)
//         {
//             instance_ = new Singleton;
//         }
//         return instance_;
//     }

// protected:
//     Singleton(); // no one can create this except itself
// private:
//     static Singleton *instance_; // the one single instance
// };

// Singleton * Singleton::instance_ = nullptr;

int main()
{

    int a = 1;
    int& b = a;

    a = 2;

    cout << b << endl;

}