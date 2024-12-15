#include <iostream>
#include <thread>
#include <mutex>
#include <chrono>

using namespace std;

mutex mutex_0;

void func0()
{
    for (int i = 0; i < 3; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(200));

        mutex_0.lock();
        cout << "func0 got the mutex \r\n";
        mutex_0.unlock();
    }
}

void func1()
{
    for (int i = 0; i < 3; i++)
    {
        this_thread::sleep_for(chrono::milliseconds(200));

        mutex_0.lock();
        cout << "func1 got the mutex \r\n";
        mutex_0.unlock();
    }
}

int main()
{
    thread thread_0(func0);
    thread thread_1(func1);

    thread_0.join();
    thread_1.join();
}