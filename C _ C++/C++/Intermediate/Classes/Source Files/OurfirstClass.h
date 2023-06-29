#pragma once

class Human
{
    // friends can see
private:
    // Later
    
    // attributes
    int age;
    char name;
    char surname;
    
    // What other classes can see
public:

    // method
    bool walk();
    bool drive();

    // What the children can see
protected:
    // Later



};