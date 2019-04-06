Input:
4
1 2 L 1 3 R 2 4 R 3 5 L

Output:
2 4 1 5 3 
0

#include <iostream>
#include <map>
using namespace std;
struct Node{
    int data;
    Node* left,*right;
};
bool isStructSame(Node *a, Node *b);
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
    cout<<root->data<<" " ;
    inorder(root->right);
}

bool ismirror(Node* root1,Node* root2){
    if(root1==nullptr && root2==nullptr)
        return true;
    if(root1 && root2 && root1->data==root2->data)
        return ismirror(root1->left,root2->right) && ismirror(root1->right,root2->left);
    return false;
}
bool isSymmetric(Node* root){
    ismirror(root,root);}
int main(){
    Node* root=nullptr;
    map<int,Node*> m;
    int n;
    cin>>n;
    //int a[n];
    for(int i=0;i<n;i++)
    {
        Node* parent;
        char  lr;
        int n1,n2;
        cin>>n1>>n2>>lr;
        if(m.find(n1)==m.end())
        {
            parent=newnode(n1);
            m[n1]=parent;
            if(root==nullptr)
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
    cout<<"\n";
    //mirror(root);
    cout << isSymmetric(root);  
    //inorder(root);a
    return 0;
}
    
    
    
