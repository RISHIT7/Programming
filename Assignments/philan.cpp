#include <iostream>
using namespace std;

class node{
    public:
    int data;
    node *next;

    node(int val){
        data=val;
        next=NULL;
    }
};
void inserAtHead(node* &head, int val){
    node* dummyNode=new node(val);
    dummyNode->next=head;
    head=dummyNode;
}

int length(node * head){
    int k=0;
    node* p3=head;
    while(p3->next!=NULL){
        k++;
        p3=p3->next;
    }
    return k;
}


void insertAtTail(node* &head, int val){
    
    node* dummyNode = new node(val);

    if(head==NULL){
        head=dummyNode;
        return;
    }
    node* p3=head; 
    // node p3, p3.next ( not a pointer, then we use p3.next )
    // node* p3, p3->next ( if our object is a pointer, then we use "->" instead of "." )
    while(p3->next!=NULL){
        p3=p3->next; // this line means, p3 ko aage badhana...
    }
    p3->next=dummyNode;  // adding a new element to the linked list
}

void display(node* head){
    node* p3 = head;
    while(p3!= NULL){
        cout<<p3->data<<"->";
        p3=p3->next;
    }
    cout<<"NULL"<<endl;
}

node* merge(node* & head1,node* &head2){
    node* p1=head1;
    node* p2=head2;


    node* dummyNode=new node(-1);
    node* p3=dummyNode;

    while(p1!=NULL && p2!=NULL){
        if(p1->data >=p2->data){
            p3->next=p2;

            p2=p2->next;

            p3=p3->next;
            
        }
        else{
            p3->next=p1;

            p1=p1->next;

            p3=p3->next;
        }
    }
    while(p1!=NULL){
        p3->next=p1;

        p1=p1->next;

        p3=p3->next;
    }
    while(p2!=NULL){
        p3->next=p2;

        p2=p2->next;

        p3=p3->next;
    }

    return dummyNode->next;
}


node* mergeRecursive(node* &head1, node* &head2){

if(head1==NULL){
    return head2;
}
if(head2==NULL){
    return head1;
}

node* result;
if(head1->data < head2->data){
    result=head1;
    result->next=mergeRecursive(head1->next,head2);
}
else{
    result=head2;
    result->next=mergeRecursive(head1,head2->next);
}

return result;
}





int main(){
    node* head1= NULL;
    node* head2= NULL;
    
    int arr1[]={1,3,7,8};
    int arr2[]={2,4,9};
    for(int i=0;i<4;i++){
        insertAtTail(head1,arr1[i]);
    }    
    for(int i=0;i<3;i++){
        insertAtTail(head2,arr2[i]);
    }

    display(head1);
    display(head2);
    // node* newhead=merge(head1,head2);

    // display(newhead);


    node* newhead1=mergeRecursive(head1,head2);

    display(newhead1);
    return 0;
}