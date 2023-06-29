#include <iostream>
using namespace std;

int main(){
    // primitive:- float, int, bool, char
    // range of int in 32 bits is 2^32-1
    // for negative and positive if MSB == 1, number is negative
    // if MSb == 0 number is positive, where MSB = most significant digit
    // however -0 dosent make sence so our range becomes [-2^31, 2^31-1]
    // float has a size of 4 byte
    // double has 8 bytes
    // char stored as ASCII table
    int ascii = 'a';
    printf("%d", ascii);
    // booleans are stored in size of 1 byte
    int a;
    a=12;
    cout<<"\nsize of int "<<sizeof(a)<<endl;
    float b;
    cout<<"size of float "<<sizeof(b)<<endl;
    return 0;
}