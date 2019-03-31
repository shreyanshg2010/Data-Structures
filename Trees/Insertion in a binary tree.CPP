Input:4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
40 20 60 10 30 
	
	
#include <iostream> 
#include <map>
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
    return 0;
}
