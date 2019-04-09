Input:
          10
         /  \
        2    7
       / \
      8   4
Output:
          8
         /  \
        4    10
       / \
      2   7


Example 2
Input:
          10
         /  \
        30   15
       /      \
      20       5
Output:
          15
         /  \
       10    20
       /      \
      5        30
      
      
 Input:4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
40 20 60 10 30 
10 20 30 40 60 
      
#include <iostream> 
#include <bits/stdc++.h>
using namespace std; 
struct Node { 
	int data; 
    Node *left, *right; 
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
void storeinorderInSet(Node* root,set<int>& s){
    if(!root)
        return;
    storeinorderInSet(root->left,s);
    s.insert(root->data);
    storeinorderInSet(root->right,s);
}
void setToBST(set<int>& s,Node* root){
    if(!root)
        return;
    setToBST(s,root->left);
    auto it=s.begin();
    root->data=*it;
    s.erase(it);
    setToBST(s,root->right);
}
void binaryTreetoBST(Node* root){
    set<int> s;
    storeinorderInSet(root,s);
    setToBST(s,root);
}
    
int main() 
{ 
    Node* root = NULL;
    map<int,Node*> m;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        Node* parent;
        char lr;
        int n1,n2;
        cin>>n1>>n2>>lr;
        if(m.find(n1)==m.end())
        {
            parent=newnode(n1);
            m[n1]=parent;
            if(root==NULL)
                root=parent;
        }
        else
            parent=m[n1];
        Node* child=newnode(n2);
        if(lr=='L')
            parent->left=child;
        else
            parent->right=child;
        m[n2]=child;
    }
       
    inorder(root);
    binaryTreetoBST(root);
    cout<<"\n";
    inorder(root);
    return 0;
}
