#include <iostream>
using namespace std;

int getBit(int n, int pos)
{
    int k = (n & (1 << pos)) != 0;
    return k;
}

int setBit(int n, int pos)
{
    return (n | (1<<pos));
}

int clearBit(int n, int pos)
{
    return (n & (~(1<<pos)));
}

int updateBit(int n, int pos, int value){
    // clear bit then set bit
    int clearedBit = n & (~(1<<pos));
    return (clearedBit | (1<<pos));
}

int main()
{
    cout<<getBit(5, 2)<<endl;
    cout<<setBit(5, 1)<<endl;
    cout<<clearBit(5, 1)<<endl;
    cout<<updateBit(5, 1, 1)<<endl;
    return 0;
}