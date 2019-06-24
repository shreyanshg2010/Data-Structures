#include<bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int key; 
	struct Node *next; 
}; 
Node *newNode(int key) 
{ 
	Node *temp = new Node; 
	temp->key = key; 
	temp->next = NULL; 
	return temp; 
} 
void printList(Node *head) 
{ 
	while (head != NULL) 
	{ 
		cout << head->key << " "; 
		head = head->next; 
	} 
	cout << endl; 
} 
void hashAndRemove(Node *head) 
{ 
	unordered_map<Node*, int> mp; 
	Node* last = NULL; 
	while(head!=NULL){ 
		if(mp.find(head) == mp.end()){ 
			mp[head]++; 
			last = head; 
			head = head->next; 
		} 
		else{ 
			last->next = NULL; 
			break; 
		} 
	} 
} 
int main() 
{ 
	Node *head = newNode(50); 
	head->next = head; 
	head->next = newNode(20); 
	head->next->next = newNode(15); 
	head->next->next->next = newNode(4); 
	head->next->next->next->next = newNode(10); 

	head->next->next->next->next->next = head->next->next; 

	hashAndRemove(head); 

	printf("Linked List after removing loop \n"); 
	printList(head); 

	return 0; 
} 
