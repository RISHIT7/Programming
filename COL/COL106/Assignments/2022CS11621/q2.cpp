#include <iostream>
using namespace std;

// -------------------------------------- With Pointers --------------------------------------

void swap_ptr(int *a, int *b)
{
    int temp = *a; // assigning the value at address pointer to be a in temp
    *a = *b;       // assigning the value at address pointed by b to value at address pointed to by a
    *b = temp;     // assigning the value in temp to the address pointed at by b
}

// ------------------------------------- Without Pointers -------------------------------------

pair<int, int> swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;

    return {a, b};
}

// ------------------------------------- Driver Code -------------------------------------

int main()
{
    int a = 5, b = 7; // initializing ints

    cout << "Before swap..." << endl;
    cout << "Value of a is: " << a << "\nThe Value of b is: " << b << endl
         << endl;

    swap_ptr(&a, &b);

    cout << "After swap..." << endl;
    cout << "Value of a is: " << a << "\nThe Value of b is: " << b << endl
         << endl;

    a = 5, b = 7; // resetting the values for part 2

    cout << "Before swap..." << endl;
    cout << "Value of a is: " << a << "\nThe Value of b is: " << b << endl
         << endl;

    pair<int, int> pi;
    pi = swap(a, b);
    a = pi.first;
    b = pi.second;

    cout << "After swap..." << endl;
    cout << "Value of a is: " << a << "\nThe Value of b is: " << b << endl
         << endl;

    return 0;
}
