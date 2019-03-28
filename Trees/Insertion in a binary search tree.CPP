Input:
7
15 10 20 8 12 16 25

Output:
8 10 12 15 16 20 25 

#include<iostream>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
};
Node* newnode(int data){
    Node* newnode=new Node;
    newnode->data=data;
    newnode->left=newnode->right=nullptr;
    return newnode;
}
void inorder(Node* root){
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void insert(Node* &root,int key){
    if(root==nullptr)
    {
        root=newnode(key);
        return;
    }
    if(key<root->data)
        insert(root->left,key);
    else
        insert(root->right,key);
}
int main(){
    Node* root=nullptr;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int key:arr)
        insert(root,key);
    inorder(root);
    return 0;
}
