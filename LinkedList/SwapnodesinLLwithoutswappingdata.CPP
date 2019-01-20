Input:  10->15->12->13->20->14,  x = 12, y = 20
Output: 10->15->20->13->12->14

Input:  10->15->12->13->20->14,  x = 10, y = 20
Output: 20->15->12->13->10->14

Input:  10->15->12->13->20->14,  x = 12, y = 13
Output: 10->15->13->12->20->14



#include<stdio.h> 
#include<stdlib.h> 
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 
void swapNodes(struct Node **head_ref, int x, int y) 
{
if (x == y) return; 
struct Node *prevX = NULL, *currX = *head_ref; 
while (currX && currX->data != x) 
{ 
	prevX = currX; 
	currX = currX->next; 
} 
struct Node *prevY = NULL, *currY = *head_ref; 
while (currY && currY->data != y) 
{ 
	prevY = currY; 
	currY = currY->next; 
} 
if (currX == NULL || currY == NULL) 
	return; 
if (prevX != NULL) 
	prevX->next = currY; 
else 
	*head_ref = currY; 
if (prevY != NULL) 
	prevY->next = currX; 
else 
	*head_ref = currX; 
struct Node *temp = currY->next; 
currY->next = currX->next; 
currX->next = temp; 
} 
void push(struct Node** head_ref, int new_data) 
{ 
	struct Node* new_node = (struct Node*) malloc(sizeof(struct Node)); 
	new_node->data = new_data; 
	new_node->next = (*head_ref); 
	(*head_ref) = new_node; 
} 
void printList(struct Node *node) 
{ 
	while(node != NULL) 
	{ 
		printf("%d ", node->data); 
		node = node->next; 
	} 
} 
int main() 
{ 
	struct Node *start = NULL; 

	/* The constructed linked list is: 
	1->2->3->4->5->6->7 */
	push(&start, 7); 
	push(&start, 6); 
	push(&start, 5); 
	push(&start, 4); 
	push(&start, 3); 
	push(&start, 2); 
	push(&start, 1); 
	printf("\n Linked list before calling swapNodes() "); 
	printList(start); 
	swapNodes(&start, 4, 3); 
	printf("\n Linked list after calling swapNodes() "); 
	printList(start); 
	return 0; 
} 
