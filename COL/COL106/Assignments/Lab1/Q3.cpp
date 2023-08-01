#include <iostream>
using namespace std;
class A
{
public:
    int id;
    A(int i)
    {
        id = i;
        cout << "Created object with ID: " << id << endl;
    }
    ~A()
    {
        cout << "Destroyed object with ID: " << id << endl;
    }
};
int main()
{
    A a1(3); // memory delocated at the end of the program
    A *a2 = new A(5); // manually memory dellocated
    // delete a2; // using the delete keyword
    return 0;
}