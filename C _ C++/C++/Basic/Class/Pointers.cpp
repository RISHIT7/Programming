#include <iostream>
using namespace std;

void increment(int a)
{
    a++;
}

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

int main()
{
    int a = 20;
    int *aptr = &a;
    cout << *aptr << endl;
    *aptr = 10;
    cout << *aptr << endl;
    // Pointer arithmetic, increment, decrement, add, subtract
    // pointers as arrays
    int b = 2;
    increment(b);
    cout << b << endl; // does not increment the value
    // swaping
    int x = 2;
    int y = 4;

    int *xptr = &x;
    int *yptr = &y;

    swap(xptr, yptr); // call by reference
    cout << a << " " << b << endl;
    return 0;
}