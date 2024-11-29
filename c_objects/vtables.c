#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdint.h>
#include <string.h>
#include <ctype.h>

// https://stackoverflow.com/a/66041487

typedef struct Vehicle Vehicle;
typedef struct Vehicle_VTable Vehicle_VTable;

struct Vehicle
{
    char *make;
    char *model;
    int year;
    const Vehicle_VTable *vtable;
};

struct Vehicle_VTable
{
    void (*print)(Vehicle *self);
};

void print_make(Vehicle *vehicle)
{
    printf("Model %s \r\n", vehicle->make);
}

static const Vehicle_VTable vtable_Person = {
    .print = print_make};

Vehicle *init_vehicle()
{
    Vehicle *vehicle = (Vehicle *)malloc(sizeof(Vehicle));
    vehicle->vtable = &vtable_Person;
    return vehicle;
}

int main()
{
    Vehicle *v_0 = init_vehicle();
    v_0->make = "Toyota";
    v_0->vtable->print(v_0);
    return 0;
}