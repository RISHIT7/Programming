#include <iostream>
#include <cmath>
#include <set>
#include <vector>
#include <map>
#include <unordered_map>
#include <queue>
#include <stack>
#include <algorithm>
#include <string>
using namespace std;

// #define int long long
#define ll long long int
#define vi vector<int>
#define pii pair<int, int>
#define vii vector<pii>
#define rep(i, a, b) for (int i = a; i < b; i++)
#define ff first
#define ss second
#define setBits(x) builtin_popcount(x)
#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);                    \
    cout.tie(NULL);
#define print_any(vec)     \
    for (auto value : vec) \
        cout << value << " ";
#define next_line cout << endl;

const int N = 1e5 + 2, MOD = 1e9 + 7;

struct node{
    int data;
    struct node* right ;
    struct node* left ;
    node(int val){
        data = val;
        left = NULL;
        right = NULL;
    }    
};

void swap(int* a, int* b ){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void calcPointers(node* root, node** first, node** mid, node** last, node** prev){
    if(root==NULL){
        return ;
    }
    calcPointers(root->left, first, mid, last, prev);

    if(prev && root->data < (*prev)->data){
        if(!*first){
            *first = *prev;
            *mid=root;
        }
    else{
        *last = root;
    }
    }
    *prev = root;

    calcPointers(root->right, first, mid, last, prev);

}

void RestoreBST(node* root){
    node* first=NULL;
    node* mid=NULL;
    node* last=NULL;
    node* prev=NULL;
    
    calcPointers(root, &first, &mid, &last, &prev);

    if(first && last){
        swap(&(first->data), &(last->data));
    }
    else if(first && mid){
        swap(&(first->data), &(mid->data));
    }
}

void inorder(node* root){
    if(root==NULL){
        return ;
    }
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}

int main(){
    node* root = new node(6);
    root->left = new node(9);
    root->right = new node(3);
    root->left->left = new node(1);
    root->left->right = new node(4);
    root->right->right = new node(13);

    inorder(root);
    cout<<endl;
    RestoreBST(root);
    
    inorder(root);
    cout<<endl;

    return 0;
}