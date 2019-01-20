#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
int data; 
struct Node* next; 
}; 
void printNthFromLast(struct Node* head, int n) 
{ 
	int len = 0, i; 
	struct Node *temp = head; 
	while (temp != NULL) 
	{ 
		temp = temp->next; 
		len++; 
	} 
	if (len < n) 
	return; 
	temp = head; 
	for (i = 1; i < len-n+1; i++) 
	temp = temp->next; 
	printf ("%d", temp->data); 
	return; 
} 

void push(struct Node** head_ref, int new_data) 
{ 
struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
new_node->data = new_data; 
new_node->next = (*head); 
(*head) = new_node; 
} 
int main() 
{ 
struct Node* head = NULL; 
// create linked 35->15->4->20 
push(&head, 20); 
push(&head, 4); 
push(&head, 15); 
push(&head, 35); 
printNthFromLast(head, 4); 
return 0; 
} 
