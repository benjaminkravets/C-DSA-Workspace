#include <future>
#include <iostream>
#include <thread>

using namespace std;

// from https://en.cppreference.com/w/cpp/thread/future

void futures()
{
    // future from packaged_task
    // packaged_task wraps a callable (in this case a lambda) so it can be invoked asyncchronously
    std::packaged_task<int()> task([]
                                   { return 1; });
    // get_future returns a future for the promised return
    std::future<int> future_0 = task.get_future();
    // packaged_tasks are not copyable; ownership is tranferred to the thread
    std::thread t(std::move(task));

    // future from an async
    // async starts a function and returns a future
    // async can have policy async (1) which runs the function in a new thread or deffered (2) which uses the caller thread
    std::future<int> future_1 = std::async(std::launch::async, []
                                           { return 2; });

    // future from promise
    // while futures are for the consumer/reader, promises are for the producer/writer
    std::promise<int> p;
    std::future<int> future_2 = p.get_future();
    // the thread sets the value of the promise, it's future can later be read
    std::thread thread_0([&p]
                         { p.set_value(3); });

    thread_0.detach();

    future_0.wait();
    future_1.wait();
    future_2.wait();

    cout << "Results: " << future_0.get() << " " << future_1.get() << " " << future_2.get() << " " << endl;

    t.join();
}

int main()
{
    futures();

    return 0;
}