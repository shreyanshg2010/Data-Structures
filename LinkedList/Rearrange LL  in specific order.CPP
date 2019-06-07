#include <bits/stdc++.h>
using namespace std;
struct Node
{
	int data;
	Node* next;
};
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}

	cout << "null\n";
}
void push(struct Node** headRef, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void rearrange(Node** head)
{
	if (*head == nullptr || (*head)->next == nullptr)
		return;
	Node *dummyFirst=(struct Node*)malloc(sizeof(struct Node));
	Node *dummySecond=(struct Node*)malloc(sizeof(struct Node));
	Node *first = dummyFirst, *second = dummySecond;
	Node *curr = *head;
	while (curr != nullptr)
	{
		first->next = curr;
		first = first->next;
		if (curr->next != nullptr)
		{
			second->next = curr->next;
			second = second->next;
			curr = curr->next;
		}
		curr = curr->next;
	}
	first->next = dummySecond->next;
	second->next = nullptr;
	*head = dummyFirst->next;
}
int main()
{
	int keys[] = { 1, 2, 3, 4, 5 };
	int n = sizeof(keys) / sizeof(keys[0]);
	Node* head = nullptr;
	for (int i = n - 1; i >= 0; i--)
		push(&head, keys[i]);
	rearrange(&head);
	printList(head);
	return 0;
}
