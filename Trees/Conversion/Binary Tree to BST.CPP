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
      
      
      
      
#include <bits/stdc++.h> 
using namespace std; 

struct Node { 
	int data; 
	struct Node *left, *right; 
}; 
void storeinorderInSet(Node* root, set<int>& s) 
{ 
	if (!root) 
		return; 
	storeinorderInSet(root->left, s); 
	s.insert(root->data); 
	storeinorderInSet(root->right, s); 

} // Time complexity = O(nlogn)  
void setToBST(set<int>& s, Node* root) 
{  
	if (!root) 
		return; 
	setToBST(s, root->left); 
	auto it = s.begin(); 
	root->data = *it; 
	s.erase(it); 
	setToBST(s, root->right); 

} // T(n) = O(nlogn) time 
void binaryTreeToBST(Node* root) 
{ 
	set<int> s; 
	storeinorderInSet(root, s); 
	setToBST(s, root); 

} // Time complexity = O(nlogn), 
// Auxiliary Space = O(n) for set. 
Node* newNode(int data) 
{ 
	Node* temp = new Node(); 
	temp->data = data; 
	temp->left = temp->right = NULL; 
	return temp; 
} 
void inorder(Node* root) 
{ 
	if (!root) 
		return; 
	inorder(root->left); 
	cout << root->data << " "; 
	inorder(root->right); 
} 
int main() 
{ 
	Node* root = newNode(5); 
	root->left = newNode(7); 
	root->right = newNode(9); 
	root->right->left = newNode(10); 
	root->left->left = newNode(1); 
	root->left->right = newNode(6); 
	root->right->right = newNode(11); 

	/* Constructing tree given in the above figure 
		5 
		/ \ 
		7	 9 
	/\ / \ 
	1 6 10 11 */

	// converting the above Binary tree to BST 
	binaryTreeToBST(root); 
	cout << "Inorder traversal of BST is: " << endl; 
	inorder(root); 
	return 0; 
} 
