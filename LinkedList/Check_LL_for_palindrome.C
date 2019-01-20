a->NULL
Not Palindrome

b->a->NULL
Not Palindrome

a->b->a->NULL
Is Palindrome

c->a->b->a->NULL
Not Palindrome

a->c->a->b->a->NULL
Not Palindrome

b->a->c->a->b->a->NULL
Not Palindrome

a->b->a->c->a->b->a->NULL
Is Palindrome



#include <stdio.h> 
#include <stdlib.h> 
#include <stdbool.h> 
struct node 
{ 
	char data; 
	struct node* next; 
}; 
bool isPalindromeUtil(struct node **left, struct node *right) 
{ 
if (right == NULL) 
	return true; 
bool isp = isPalindromeUtil(left, right->next); 
if (isp == false) 
	return false; 
bool isp1 = (right->data == (*left)->data); 
*left = (*left)->next; 
return isp1; 
} 
bool isPalindrome(struct node *head) 
{ 
isPalindromeUtil(&head, head); 
} 
void push(struct node** head, char new_data) 
{ 
	struct node* new_node = (struct node*) malloc(sizeof(struct node)); 
	new_node->data = new_data; 
	new_node->next = (*head); 
	(*head) = new_node; 
} 
void printList(struct node *ptr) 
{ 
	while (ptr != NULL) 
	{ 
		printf("%c->", ptr->data); 
		ptr = ptr->next; 
	} 
	printf("NULL\n"); 
} 
int main() 
{ 
	struct node* head = NULL; 
	char str[] = "abacaba"; 
	int i; 
	for (i = 0; str[i] != '\0'; i++) 
	{ 
	push(&head, str[i]); 
	printList(head); 
	isPalindrome(head)? printf("Is Palindrome\n\n"): printf("Not Palindrome\n\n"); 
	} 
	return 0; 
} 
