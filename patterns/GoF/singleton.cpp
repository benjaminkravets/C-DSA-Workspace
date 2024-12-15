#include <iostream>


using namespace std;

// From "Making Embedded Systems" (White)

// A single-instance class- allows lazy allocation/initialization
class Singleton
{

public:
    void Log(char *logmsg)
    {
        cout << "Logged " << logmsg << endl;
    }
    static Singleton *GetInstance()
    {
        if (instance_ == NULL)
        {
            instance_ = new Singleton;
        }
        return instance_;
    }

protected:
    Singleton() = default;

private:
    static Singleton *instance_;
};

Singleton *Singleton::instance_ = nullptr;

int main()
{
    char msg[] = "msg";
    Singleton::GetInstance()->Log(msg);
}