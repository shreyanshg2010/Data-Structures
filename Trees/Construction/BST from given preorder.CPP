Output:
Inorder traversal of the constructed tree: 
1 5 7 10 40 50 


#include <iostream> 
#include <climits>
using namespace std; 
struct Node{
    int data;
    Node* left,*right;
};
Node* newnode(int data){
    Node* temp=new Node;
    temp->data=data;
    temp->left=temp->right=nullptr;
    return temp;
}
Node* constructTreeUtil(int pre[],int *preIndex,int key,int min,int max,int size){
    if(*preIndex>=size)
        return NULL;
    Node* root=NULL;
    if(key>min && key<max){
        root=newnode(key);
        *preIndex=*preIndex+1;
        if(*preIndex<size){
            root->left =constructTreeUtil(pre,preIndex,pre[*preIndex],min,key,size);  
            root->right=constructTreeUtil(pre,preIndex,pre[*preIndex],key,max,size); 
        }
    }
    return root;
}
Node *constructTree (int pre[], int size) 
{ 
    int preIndex = 0; 
    return constructTreeUtil ( pre, &preIndex, pre[0], INT_MIN,  
                               INT_MAX, size ); 
} 
void printInorder (Node* node) 
{ 
    if (node == NULL) 
        return; 
    printInorder(node->left); 
    cout<<node->data<<" "; 
    printInorder(node->right); 
} 
int main () 
{ 
    int pre[] = {10, 5, 1, 7, 40, 50}; 
    int size = sizeof( pre ) / sizeof( pre[0] ); 
    Node *root = constructTree(pre, size); 
    cout<<"Inorder traversal of the constructed tree: \n"; 
    printInorder(root); 
  
    return 0; 
} 
