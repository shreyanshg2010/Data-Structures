Input:
6
4 2 5 1 3 6 
1 2 4 5 3 6

Output:
Postorder traversal 
4 5 2 6 3 1 

#include <iostream> 
using namespace std; 
int search(int arr[], int x, int n) 
{ 
	for (int i = 0; i < n; i++) 
		if (arr[i] == x) 
			return i; 
	return -1; 
} 

void printPostOrder(int in[], int pre[], int n) 
{ 
	int root = search(in, pre[0], n); 
	if (root != 0) 
		printPostOrder(in, pre + 1, root); 
	if (root != n - 1) 
		printPostOrder(in + root + 1, pre + root + 1, n - root - 1); 
	cout << pre[0] << " "; 
}  
int main() 
{ int n;
  cin>>n;
	int in[n];
  for(int i=0;i<n;i++)
  cin>>in[i];
	int pre[n];
  for(int i=0;i<n;i++)
  cin>>pre[i];
	cout << "Postorder traversal " << endl; 
	printPostOrder(in, pre, n); 
	return 0; 
} 
