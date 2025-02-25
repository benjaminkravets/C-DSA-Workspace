#include <cstddef>
#include <concepts>
#include <functional>
#include <string>
#include <vector>
#include <iostream>
#include <type_traits>
#include <iostream>
using namespace std;

// enable_if intentionally causes substitution failures (don't consider this for overload resolution)

template <bool Condition, typename T>
// if Condition is true, the typedef 'type' is defined to be second parameter (void by default)
typename enable_if<Condition, void>::type // this line says 'if Condition is True, use type void'- effectively this line could be 'void'
foo(T value)
{
    std::cout << "True case: " << value << std::endl;
}

template <bool Condition, typename T>
typename enable_if<!Condition, void>::type
foo(T value)
{
    std::cout << "False case: " << value << std::endl;
}

// type trait evaluations can be used as conditions in enable_if
template <typename T>
typename std::enable_if<std::is_integral<T>::value, void>::type bar(T x)
{
    cout << "integer" << endl;
}

template <typename T>
typename std::enable_if<std::is_floating_point<T>::value, void>::type bar(T x)
{
    cout << "float" << endl;
}

template <typename T>
typename std::enable_if<!std::is_integral<T>::value && !std::is_floating_point<T>::value, void>::type bar(T x)
{
    cout << "other" << endl;
}

// enable_if can also be used to disqualify function templates based on paramter types
// here, the second function parameter isn't used by the function body, it helps determine which template should be used
template <typename T>
void fonzie(T a, typename enable_if<is_integral<T>::value, int>::type = 0)
{
    cout << "integer" << endl;
}

template <typename T>
void fonzie(T a, typename enable_if<is_floating_point<T>::value, int>::type = 0)
{
    cout << "float" << endl;
}

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
