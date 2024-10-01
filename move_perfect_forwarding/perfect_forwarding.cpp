#include <iostream>
#include <algorithm>
#include <memory>
#include <cstring>

using namespace std;


void func_0(int& a, int& b){
   a++;
   b++;
}

void func_2(const int& a, const int& b){
   cout << a << " " << b << " " << endl;
}


template <typename T1, typename T2>
void wrapper_0(T1 e1, T2 e2) {
    func_0(e1, e2);
}

template <typename T1, typename T2>
void wrapper_1(T1& e1, T2& e2) {
    func_0(e1, e2);
}

template <typename T1, typename T2>
void wrapper_2(const T1& e1, const T2& e2) {
    func_2(e1, e2);
}

template <typename T1, typename T2>
//In this case, these (&&) are universal references (officially "forwarding reference")- it will be deduced as an lvalue reference or an rvalue reference
void wrapper_3(T1&& e1, T2&& e2) {
    func_0(forward<T1>(e1),forward<T2>(e2));
}


int main(){


   //The goal is to have a function template call func to perform an increment on a and b by forwarding variables (which should act as they would using a call to the function)
   int a = 1, b = 2;
   int& c = a;
   int& d = b;

   //wrapper_0 doesn't result in a or b being incremented even though a call to func_0 would.
   //wrapper_0(c,d);

   //wrapper_1 works, but if func_0 ever needed r-values, it wouldn't.
   //wrapper_1(c,d);

   //wrapper_2 uses const X& since this binds to rvalues and lvalue references, but now the arguments have to be const and the function can't increment the passed variables
   // const int& e = a;
   // const int& f = b;
   // wrapper_2(e,f);
   // wrapper_2(1,2);

   //A final solution would be to have a wrapper for every permutation of the arguments (2^n for n arguments).
   //This is not maintainable, but forward() can wrap this for us.
   //wrapper_3 can take an rvalue

   //wrapper_3(a,b);
   

   cout << a << " " << b << endl;

}