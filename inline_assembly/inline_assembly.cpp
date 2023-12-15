

#include <algorithm>
#include <iostream>
using namespace std;

int power2( int num, int power )
{
   __asm
   {
      mov eax, num    ; Get first argument
      mov ecx, power  ; Get second argument
      shl eax, cl     ; EAX = EAX * ( 2 to the power of CL )
   }
   // Return with result in EAX
}

int adder( int num, int num2 )
{
   __asm
   {
      mov eax, num    ; Get first argument
      adc eax, num2     ; EAX = EAX * ( 2 to the power of CL )
   }
   // Return with result in EAX
}
  
int main() 
{ 
    int a = 5;
    int b = 3;
    int c = adder(a,b);

    cout << c << endl;


}