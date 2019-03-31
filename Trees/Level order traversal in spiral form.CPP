Input:
4
10 20 L 10 30 R 20 40 L 20 60 R

Output:
40 20 60 10 30 
Spiral Order traversal of binary tree is 
10 20 30 60 40 


#include <iostream> 
#include <stack> 
#include <map>
using namespace std; 
struct Node { 
	int data; 
    Node *left, *right; 
}; 
void printSpiral(Node* root) 
{ 
	if (root == NULL) 
		return; 
	stack<struct Node*> s1; 
	stack<struct Node*> s2; 
	s1.push(root); 
	while (!s1.empty() || !s2.empty()) {
		while (!s1.empty()) { 
			struct Node* temp = s1.top(); 
			s1.pop(); 
			cout << temp->data << " "; 
			if (temp->right) 
				s2.push(temp->right); 
			if (temp->left) 
				s2.push(temp->left); 
		} 
		while (!s2.empty()) { 
			struct Node* temp = s2.top(); 
			s2.pop(); 
			cout << temp->data << " "; 
			if (temp->left) 
				s1.push(temp->left); 
			if (temp->right) 
				s1.push(temp->right); 
		} 
	} 
} 
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
	cout << "\nSpiral Order traversal of binary tree is \n"; 
	printSpiral(root); 

	return 0; 
} 
