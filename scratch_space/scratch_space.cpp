#include <cstddef>
#include <concepts>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <type_traits>
#include <iostream>
using namespace std;


int main()
{
    // foo<true>(42);
    // foo<false>("Hello");

    // bar(1);
    // bar(1.2);
    // bar("Hello world");

    fonzie(1);
    fonzie(1.2);

    return 0;
}
