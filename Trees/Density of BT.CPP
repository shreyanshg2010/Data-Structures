//C++ program to find density of a binary tree 
#include<stdio.h> 
#include<stdlib.h> 

// A binary tree node 
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 

// Helper function to allocates a new node 
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return node; 
} 

// Function to compute height and 
// size of a binary tree 
int heighAndSize(Node* node, int &size) 
{ 
	if (node==NULL) 
		return 0; 

	// compute height of each subtree 
	int l = heighAndSize(node->left, size); 
	int r = heighAndSize(node->right, size); 

	//increase size by 1 
	size++; 

	//return larger of the two 
	return (l > r) ? l + 1 : r + 1; 
} 

//function to calculate density of a binary tree 
float density(Node* root) 
{ 
	if (root == NULL) 
		return 0; 

	int size = 0; // To store size 

	// Finds height and size 
	int _height = heighAndSize(root, size); 

	return (float)size/_height; 
} 

// Driver code to test above methods 
int main() 
{ 
	Node* root = newNode(1); 
	root->left = newNode(2); 
	root->right = newNode(3); 

	printf("Density of given binary tree is %f", 
		density(root)); 

	return 0; 
} 
