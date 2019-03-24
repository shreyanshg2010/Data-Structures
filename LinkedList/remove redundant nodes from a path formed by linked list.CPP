![Redundant-nodes](https://user-images.githubusercontent.com/31040579/54881378-2c20d480-4e75-11e9-941c-5d60a7a6fae9.png)

Input:
8
0 1
0 5
0 8
2 8
5 8
7 8
7 10
7 12


Output:
(0, 1) -> (0, 8) -> (7, 8) -> (7, 12) -> null


#include <stdio.h>
#include <stdlib.h>
struct Node {
	int x, y;
	struct Node* next;
};
void push(struct Node** head, int x, int y)
{
	struct Node* node = (struct Node*)malloc(sizeof(struct Node));
	node->x = x;
	node->y = y;
	node->next = *head;
	*head = node;
}
void removeNodes(struct Node **head)
{
	struct Node* curr = *head;
	while (curr->next && curr->next->next)
	{
		struct Node *temp = curr->next->next;
		if (curr->x == curr->next->x && curr->x == temp->x)
		{
			free(curr->next);
			curr->next = temp;
		}
		else if (curr->y == curr->next->y && curr->y == temp->y)
		{
			free(curr->next);
			curr->next = temp;
		}
		else
		{
			curr=curr->next;
		}
	}
}
void printList(struct Node* head)
{
	struct Node* ptr = head;
	while (ptr)
	{
		printf("(%d, %d) -> ", ptr->x, ptr->y);
		ptr = ptr->next;
	}
	printf("null\n");
}
int main()
{
	int n ;
    scanf("%d",&n);
    int arr[n][2];
    for(int i=0;i<n;i++){
        for(int j=0;j<2;j++){
            scanf("%d",&arr[i][j]);}}
	struct Node* head = NULL;
	for (int i = n - 1; i >= 0; i--)
		push(&head, arr[i][0], arr[i][1]);
	removeNodes(&head);
	printList(head);

	return 0;
}
