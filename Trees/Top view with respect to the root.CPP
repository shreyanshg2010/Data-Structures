Input:
6
1 2 5 3 6 4

Output:
1 2 5 6 


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
   void for_left(Node * root)
{
    if(root->left!=NULL)
        for_left(root->left);
    cout<<root->data<<" ";
}
void for_right(Node * root)
{
    cout<<root->data<<" ";
    if(root->right!=NULL)
        for_right(root->right);
}
void topView(Node * root)
{
    if(root->left!=NULL)
        for_left(root->left);
    cout<<root->data<<" ";
    if(root->right!=NULL)
        for_right(root->right);
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
    cout<<"\n";
    topView(root);
    return 0;
}
