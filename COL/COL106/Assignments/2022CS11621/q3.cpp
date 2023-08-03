#include <iostream>
using namespace std;

class A
{
public:
    int id;
    A(int i)
    {
        id = i;
        cout << "Created objet with ID: " << id << endl;
    }

    ~A()
    {
        cout << "Destroyed object with ID: " << id << endl;
    }
};

int main()
{

    A a1(3);          // allocated memory in the stack and deleted at the end of the program
    A *a2 = new A(5); // allocated memory in the heap
    delete a2;        // deleted whenever the keyword "delete" is used

    return 0;
}
