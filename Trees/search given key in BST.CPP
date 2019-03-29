Input:
7
15 10 20 8 12 16 25
25

Output:
8 10 12 15 16 20 25 
Given key is right node of node with key 20

#include <iostream>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
};
Node* newNode(int data){
    Node* newnode=new Node;
    newnode->data=data;
    newnode->left=newnode->right=nullptr;
    return newnode;
}
void insert(Node* &root,int data){
    if(root==nullptr){
        root=newNode(data);
        return;
    }
    if(data<root->data)
        insert(root->left,data);
    else
        insert(root->right,data);
}
void inorder(Node* root){
    if(root==nullptr)
        return;
    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);
}
void search(Node* root,int key,Node* parent){
    if(root==nullptr){
        cout<<"key not found";
        return;
    }
    if(root->data==key){
        if(parent==nullptr)
            cout << "The node with key " << key << " is root node";
        else if (key < parent->data)
			cout << "Given key is left node of node with key " 
				 << parent->data;

		else cout << "Given key is right node of node with key " 
				 << parent->data;

		return;
    }
    if(key<root->data)
        return search(root->left,key,root);
    return search(root->right,key,root);
}

    
int main(){
    Node* root=nullptr;
    int n;
    cin>>n;
    int arr[n];
    for(int i=0;i<n;i++)
        cin>>arr[i];
    for(int keys:arr)
        insert(root,keys);
    inorder(root);
    cout<<"\n";
    int key=25;
    search(root,key,nullptr);
    return 0;
}
