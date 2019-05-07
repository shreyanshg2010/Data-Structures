#include <iostream> 
#include <stack> 
#include <queue> 
using namespace std; 
struct Node 
{ 
	int data; 
	Node* left; 
	Node* right; 
}; 
void reverseLevelOrder(Node* root) 
{ 
	stack <Node *> S; 
	queue <Node *> Q; 
	Q.push(root); 
	while (Q.empty() == false) 
	{ 
		root = Q.front(); 
		Q.pop(); 
		S.push(root); 
		if (root->right) 
			Q.push(root->right);
		if (root->left) 
			Q.push(root->left); 
	} 
	while (S.empty() == false) 
	{ 
		root = S.top(); 
		cout << root->data << " "; 
		S.pop(); 
	} 
}
Node* newNode(int data) 
{ 
	Node* temp = new Node; 
	temp->data = data; 
	temp->left = NULL; 
	temp->right = NULL; 

	return (temp); 
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
       
	cout << "Level Order traversal of binary tree is \n"; 
	reverseLevelOrder(root); 

	return 0; 
} 
