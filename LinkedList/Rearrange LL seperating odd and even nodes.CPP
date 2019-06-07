#include <stdio.h>
#include <stdlib.h>
struct Node
{
	int data;
	struct Node* next;
};
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("%d -> ", ptr->data);
		ptr = ptr->next;
	}

	printf("NULL\n");
  }
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void rearrange(struct Node* head, struct Node* odd, struct Node* even, 
				struct Node** oddRef)
{
	if (head == NULL) 
	{
		odd->next = NULL;
		even->next = (*oddRef)->next;
		return;
	}
	if (head->data & 1) 
	{
		odd->next = head;
		rearrange(head->next, head, even, oddRef);
	}
	else 
	{
		even->next = head;
		rearrange(head->next, odd, head, oddRef);
	}
}
void rearrangeEvenOdd(struct Node** head)
{
	struct Node* odd = (struct Node*)malloc(sizeof(struct Node));
	struct Node* even = (struct Node*)malloc(sizeof(struct Node));
	rearrange(*head, odd, even, &odd);
	*head = even->next;
	free(odd);
	free(even);
}
int main()
{
	int keys[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
	int n = sizeof(keys)/sizeof(keys[0]);
	struct Node* head = NULL;
	for (int i = n - 1; i >=0; i--)
		push(&head, keys[i]);
	rearrangeEvenOdd(&head);
	printList(head);
	return 0;
}
