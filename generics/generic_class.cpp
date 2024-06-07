#include <iostream>
using namespace std;

template <typename T>
class Array
{

private:
    T *ptr;
    int size;

public:
    Array(T arr[], int s)
    {
        ptr = new T[s];
        size = s;

        for (int i = 0; i < size; i++)
        {
            ptr[i] = arr[i];
        }
    }
    void print()
    {
        for (int i = 0; i < size; i++)
        {
            cout << " " << *(ptr + i);
        }
        cout << endl;
    }
    ~Array()
    {
        delete ptr;
    }
};

int main()
{
    char char_array[5] = {'a', 'c', 'j', 'r', 'j'};
    Array<char> a(char_array, 5);
    a.print();

    double double_array[3] = {2.2, 5.12, 9.2};
    Array<double> b(double_array, 3);
    b.print();
    return 0;
}