#include <iostream>
#include <string.h>
using namespace std;


//from https://stackoverflow.com/a/4571683

class List
{

    class Node
    {
    public:
        int data;
        Node *next;
        Node *prev;
    };
    Node *head;
    Node *tail;

public:
    List() : head(nullptr), tail(nullptr) {}
};

void class_in_class()
{
    List outer_0;
}

void class_in_function()
{
    class Outer
    {
        public:
        int x;
    };
    Outer outer_0;
    outer_0.x = 2;
}

int main()
{
    class_in_class();
    class_in_function();
}