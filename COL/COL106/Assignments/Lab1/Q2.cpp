#include <iostream>  // including the i/o stream of c++
using namespace std; // using the namespace std

// -------------------------------- With Pointers --------------------------------

void swap_ptr(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

// ------------------------------ Without Pointers -------------------------------

pair<int, int> swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
    return {a, b};
}

int main()
{
    int a = 5, b = 7; // defining variables

    cout << "Before swap..." << endl;
    cout << "Value of a is: " << a << "\nThe Value of b is: " << b << endl
         << endl;

    // swap_ptr(&a, &b);

    pair<int, int> pi;
    pi = swap(a, b);
    a = pi.first;
    b = pi.second;

    cout << "After swap..." << endl;
    cout << "Value of a is: " << a << "\nThe Value of b is: " << b << endl
         << endl;

    return 0;
}