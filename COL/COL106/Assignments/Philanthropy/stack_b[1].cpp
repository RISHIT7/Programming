#include<iostream>
#include<stdexcept>
#include "stack_b.h"
using namespace std;

Stack_B::Stack_B(){
    size=0;
    capacity=1024;
    stk = new int[capacity];
}    
Stack_B::~Stack_B(){
    delete stk;
}
void Stack_B::push(int data){
    if (size==capacity){
        capacity*=2;
        int* temp=new int[capacity];
        //if (!temp){
        //    throw runtime_error("Out of Memory");
        //}
        for (int i=0;i<size;i++){
            temp[i]=stk[i];
        }
        delete stk;
        stk=temp;
    }
    stk[size]=data;
    size+=1;
}

int Stack_B::pop(){
    if (size==0){
        throw runtime_error("Empty Stack");
    }
    int res=stk[size-1];
    size-=1;
    if (size==capacity/2){
        capacity/=2;
        int* temp=new int[capacity];
        for (int i=0;i<size;i++){
            temp[i]=stk[i];
        }
        delete stk;
        stk=temp;
    }
    return res;
}

int Stack_B::get_element_from_top(int idx){
    if (idx>size){
        throw runtime_error("Index out of range");
    }
    return stk[size-idx-1];
}

int Stack_B::get_element_from_bottom(int idx){
    if (idx>size){
        throw runtime_error("Index out of range");
    }
    return stk[idx];
}

void Stack_B::print_stack(bool top_or_bottom){
   if (top_or_bottom==1){
        for (int i=size-1;i>=0;i--){
            cout<<stk[i]<<endl;
        }
    }
    else{
        for (int i=0;i<size;i++){
            cout<<stk[i]<<endl;
        }
    }
}

int Stack_B::add(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int t=stk[size-2]+stk[size-1];
    this->pop();
    this->pop();
    this->push(t);
    size-=1;
    return t;
}
int Stack_B::subtract(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int t=stk[size-2]-stk[size-1];
    this->pop();
    this->pop();
    this->push(t);
    size-=1;
    return t;
}
int Stack_B::multiply(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    int t=stk[size-2]*stk[size-1];
    this->pop();
    this->pop();
    this->push(t);
    size-=1;
    return t;
}
int Stack_B::divide(){
    if (size<2){
        throw runtime_error("Not Enough Arguments");
    }
    else if(stk[size-1]==0){
        throw runtime_error( "Divide by Zero Error");
    }
    int t=stk[size-2]/stk[size-1]-1;
    if (t>=0){
        t+=1;
    }
    this->pop();
    this->pop();
    this->push(t);
    size-=1;
    return t;
}

int* Stack_B::get_stack(){
    return stk;
} // Get a pointer to the array

int Stack_B::get_size(){
    return size;
} // Get the size of the stack
int main(){
    Stack_B s = Stack_B();
    s.push (2);
    s.push (10);
    s.push (-6);
    s.push (4);
    s.push (-15);
    s.push (4);
    s.push (5);
    s.push (11);
    s.push (-9);
    s.push (-7);
    cout<<s.add()<<endl;
    cout<<s.add()<<endl;
    cout<<s.add()<<endl;
    cout<<s.subtract()<<endl;
    cout<<s.subtract()<<endl;
    cout<<s.divide()<<endl;
    cout<<s.divide()<<endl;
    cout<<s.multiply()<<endl;
    cout<<s.multiply()<<endl;
    return 0;
}