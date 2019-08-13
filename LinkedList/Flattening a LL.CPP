input:
      5 -> 10 -> 19 -> 28 
       |    |     |     | 
       V    V     V     V 
       7    20    22    35 
       |          |     | 
       V          V     V 
       8          50    40 
       |                | 
       V                V 
       30               45 
       
       
output:      5->7->8->10->19->20->20->22->30->35->40->45->50->null






#include <stdio.h>
#include <stdlib.h>
#define SIZE(arr) (sizeof(arr)/sizeof(arr[0]))
struct Node {
	int data;
	struct Node *next;
	struct Node *down;
};
void push(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = NULL;
	newNode->down = *headRef;
	*headRef = newNode;
}
struct Node* SortedMerge(struct Node* a, struct Node* b)
{
	// Base cases
	if (a == NULL)
		return b;
	else if (b == NULL)
		return a;
	struct Node* result = NULL;
	if (a->data <= b->data)
	{
		result = a;
		result->down = SortedMerge(a->down, b);
	}
	else
	{
		result = b;
		result->down = SortedMerge(a, b->down);
	}

	return result;
}
struct Node* flatten(struct Node* head)
{
	if (head == NULL)
		return head;
	struct Node* sorted = SortedMerge(head, flatten(head->next));
	head->next = NULL;
	return sorted;
}
void printList(struct Node *node)
{
	while (node) {
		printf("%d -> ", node->data);
		node = node->down;
	}
	printf("NULL");
}
void createVerticalList(struct Node **head, int arr[], int n)
{
	for (int i = 0; i < n; i++)
		push(head, arr[i]);
}

// main function
int main()
{
	struct Node* head = NULL;
    int arr1[] = { 8, 6, 4, 1 };
	int arr2[] = { 7, 3, 2 };
	int arr3[] = { 9, 5 };
	int arr4[] = { 12, 11, 10 };
	createVerticalList(&(head), arr1, SIZE(arr1));
	createVerticalList(&(head->next), arr2, SIZE(arr2));
	createVerticalList(&(head->next->next), arr3, SIZE(arr3));
	createVerticalList(&(head->next->next->next), arr4, SIZE(arr4));
	flatten(head);
	printList(head);

	return 0;
}
