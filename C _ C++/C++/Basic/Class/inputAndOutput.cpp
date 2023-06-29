#include <iostream>
using namespace std;
// preprocessor directive to include required file
// iostream = header file for taking input and printing output

int main(){
    // std::cout displays whatever is written in cout
    int amount1;
    cout<<"The money that the dad gave was: ";
    cin>>amount1; // >> extraction operator

    int amount2;
    cout<<"The money that the mom gave was: ";
    cin>>amount2;

    int sum = amount1+amount2;
    cout<<"The total money he has is: ";
    cout<<sum;
    return 0;
}