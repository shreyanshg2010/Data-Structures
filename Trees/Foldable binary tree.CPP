Input:
4
1 2 L 1 3 R 2 4 R 3 5 L

Output:
2 4 1 5 3 
tree is foldable
2 4 1 5 3 

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
void mirror(Node* node){
    if(node==nullptr)
        return;
    else{
        Node* temp;
        mirror(node->left);
        mirror(node->right);
        temp=node->left;
        node->left=node->right;
        node->right=temp;}
}
bool isfoldable(Node* root){
    bool res;
    if(root==nullptr)
        return true;
    mirror(root->left);
    res=isStructSame(root->left,root->right);
    mirror(root->left);
    return res;
}
bool isStructSame(Node* a,Node* b){
    if(a==nullptr && b==nullptr)
    {return true;}
    if(a!=nullptr && b!=nullptr && isStructSame(a->left,b->left) && isStructSame(a->right,b->right))
        return true;
    return false;
}
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
    if(isfoldable(root) == 1)  
    {  
        cout << "tree is foldable\n";  
    }  
    else
    {  
        cout << "\ntree is not foldable";  
    }  
    inorder(root);
    return 0;
}
    
    
    
