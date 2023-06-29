// functions inside a class are called methods

#include <iostream>
#include "OurfirstClass.h"
using namespace std;

bool Human::walk()
{
    return true;
}

bool Human::drive()
{
    return false;
}

int main()
{
    // Class and an Object are different, the class is a template and john is an object of the class Human

    int i = 5;
    Human John; // this is for a human "named" h

    float f;
    John.age = 24;
    John.walk = true;

    i = John.age;
    cout << i << endl;
    return 0;
}