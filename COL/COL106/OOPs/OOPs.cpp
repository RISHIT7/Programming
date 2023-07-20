#include <iostream>
using namespace std;

class myClass
{
    // Class data
    string name;

public:
    int age;
    string gender;

    myClass(string s, int a, string g)
    {
        cout << "Parameterized constructor" << endl;
        name = s;
        age = a;
        gender = g;
    };

    myClass()
    {
        cout << "Default constructor" << endl;
    };

    myClass(myClass &a)
    {
        cout << "Copy constructor" << endl;
        name = a.name;
        age = a.age;
        gender = a.gender;
    }
    ~myClass()
    {
        cout << "Destructor called" << endl;
    }
    string getName()
    {
        return name;
    }
    void setName(string s)
    {
        name = s;
    }
    bool operator==(myClass &a)
    {
        if ((name == a.name) && (age == a.age) and (gender == a.gender))
        {
            return true;
        }
        return false;
    }
};

int main()
{
    myClass me = myClass("rishit", 24, "M");
    myClass other = myClass("ki", 24, "M");
    // cout << boy.age << " " << boy.gender << " " << boy.getName() << endl;
    if (not(me == other))
    {
        cout << "YO" << endl;
    }
    return 0;
}