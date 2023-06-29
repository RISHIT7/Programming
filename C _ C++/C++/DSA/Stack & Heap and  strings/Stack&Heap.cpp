// Stack like memory stack have a fixed size
// Heap have dynamic memory, used for dynamic memory allocation
#include <iostream>
using namespace std;

int main()
{
    int a = 10;         // memory allocated in stack
    int *p = new int(); // allocate momery in heap
    *p = 10;
    delete (p);
    p = new int[4]; // reallocation , pointing to arr[0]

    delete[] p; // deallocation, dangling pointer
    p = NULL; // to remove the dangling pointer, i.e. remove the pointer alltogether
    // if memory is not deleted, then memory leak may happen, and hence imp to remove
    return 0;
}
// Heap 
// 200 = 10
// stack
// p = 200 hence it's like a pointer, like a global variable