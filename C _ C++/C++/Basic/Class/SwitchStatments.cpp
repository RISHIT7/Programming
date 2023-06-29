#include <iostream>
using namespace std;

int main()
{
    char button;
    cout<<"Input a character: ";
    cin>>button;

    switch (button)
    {
    case 'a':
        cout<<"Hello"<<endl;
        break;
    case 'b':
        cout<<"Namaste"<<endl;
        break;
    case 'c':
        cout<<"Hola"<<endl;
        break;
    case 'd':
        cout<<"Ciao"<<endl;
        break;
    default:
        cout<<"I am still learning more"<<endl;
        break;
    }

    return 0;
}