/*
Polymorphism -------------------------
    |                                |
    |                                |
    V                                V
    Compile time                   Run time
Function Overloading,              Virtual Functions
            Operator Overloading
*/

#include <bits/stdc++.h>
using namespace std;

// ---------------- EXAMPLE 1 ----------------------

class ApnaCollege
{
public:
    void func()
    {
        cout << "I am a function with no arguments" << endl;
    }

    void func(int x)
    {
        cout << "I am a function with int arguments" << endl;
    }

    void func(double x)
    {
        cout << "I am a function with double arguments" << endl;
    }
};

// ------------------ EAXMPLE 2 --------------------

class Complex
{
private:
    int real, imag;

public:
    Complex(int r, int i)
    {
        real = r;
        imag = i;
    }

    Complex operator+(Complex const &obj)
    {
        Complex res = Complex(0, 0);
        res.imag = imag + obj.imag;
        res.real = real + obj.real;
        return res;
    }

    void display()
    {
        cout << real << " + i" << imag << endl;
    }
};

class base
{
public:
    virtual void print() // dynamically binds
    {
        cout << "This is the base class's print function" << endl;
    }
    void display()
    {
        cout << "This is the base class's display function" << endl;
    }
};

/// @brief 
/// @return 
class derived : public base
{
public:
    void print()
    {
        cout << "This is the derived class's print function" << endl;
    }
    void display()
    {
        cout << "This is the derived class's display function" << endl;
    }
};

int32_t main()
{
    // ApnaCollege obj;
    // obj.func();
    // obj.func(4);
    // obj.func(6.3);

    // Complex num1 = Complex(1, 2);
    // Complex num2 = Complex(2, 3);
    // num1.display();
    // Complex num3 = num1 + num2;
    // num3.display();

    base *baseptr;
    derived d;
    baseptr = &d;

    baseptr -> print();
    baseptr -> display();
    return 0;
}