#include <iostream>
using namespace std;

int main()
{
    int i = 1;
    int j = 2;
    int k;
    //  1   2   1     2       3     4
    k = i + j + i++ + j++ + ++i + ++j;
    cout<<k<<endl;
    // && and, || or, ! not operator, ~ ones complement, ^ XOR, << left shift, >> right shift
    int a = 4;
    cout<< (a<<1)<<" "<<(a>>1) <<endl;
    // size of => return size of
    // ternary operator is a "one line form" of if else => c = a>b ? a-b : b-a
    
    return 0;
}