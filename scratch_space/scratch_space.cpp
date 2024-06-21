

#include <iostream>
using namespace std;

class Singleton {
public:
  int a;
  static Singleton* GetInstance() {

    if (instance_ == NULL) {
      instance_ = new Singleton;
    }
    return instance_;
  }
protected:
  Singleton(); // no one can create this except itself
private:
  static Singleton* instance_; // the one single instance
};
// Define the one and only Singleton pointer
Singleton* Singleton::instance_ = nullptr;


int main()
{

  Singleton::GetInstance();

}