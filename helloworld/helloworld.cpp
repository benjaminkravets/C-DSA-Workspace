// derived from geeksforgeeks.com
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <string.h>
#include <regex>
using namespace std;

// base class
union geek {
    // Defining data members
    int age;
    char grade;
    float GPA;
};
  
int main()
{
  
    // Defining a union variable
    union geek student1;
  
    // Assigning values to data member of union geek and
    // printing the values of data members
    student1.age = 25;
    cout << "Age : " << student1.age << endl;
  
    student1.grade = 'B';
    cout << "Grade : " << student1.grade << endl;
  
    student1.GPA = 4.5;
    cout << "GPA : " << student1.GPA << endl;
  
    return 0;
}