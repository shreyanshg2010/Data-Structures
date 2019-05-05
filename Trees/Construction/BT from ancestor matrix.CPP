#include <bits/stdc++.h> 
using namespace std; 
# define N 6 
struct Node 
{ 
	int data; 
	Node *left, *right; 
}; 
Node* newNode(int data) 
{ 
	Node* node = new Node; 
	node->data = data; 
	node->left = node->right = NULL; 
	return (node); 
} 
Node* ancestorTree(int mat[][N]) 
{ 
	int parent[N] = {0};  
	Node* root = NULL; 
	multimap<int, int> mm; 

	for (int i = 0; i < N; i++) 
	{ 
		int sum = 0;
		for (int j = 0; j < N; j++) 
			sum += mat[i][j]; 
		mm.insert(pair<int, int>(sum, i)); 
	} 
	Node* node[N]; 
	for (auto it = mm.begin(); it != mm.end(); ++it) 
	{ 
	node[it->second] = newNode(it->second);
	root = node[it->second]; 
	if (it->first != 0) 
	{ 
		for (int i = 0; i < N; i++) 
		{ 
		if (!parent[i] && mat[it->second][i]) 
		{ 
			if (!node[it->second]->left) 
			node[it->second]->left = node[i]; 
			else
			node[it->second]->right = node[i]; 

			parent[i] = 1; 
		} 
		} 
	} 
	} 
	return root; 
} 
void printInorder(Node* node) 
{ 
	if (node == NULL) 
		return; 
	printInorder(node->left); 
	printf("%d ", node->data); 
	printInorder(node->right); 
} 
int main() 
{ 
	int mat[N][N] = {{ 0, 0, 0, 0, 0, 0 }, 
		{ 1, 0, 0, 0, 1, 0 }, 
		{ 0, 0, 0, 1, 0, 0 }, 
		{ 0, 0, 0, 0, 0, 0 }, 
		{ 0, 0, 0, 0, 0, 0 }, 
		{ 1, 1, 1, 1, 1, 0 } 
	}; 

	Node* root = ancestorTree(mat); 

	cout << "Inorder traversal of tree is \n"; 
	printInorder(root); 

	return 0; 
} 
