Created Linked List: 
 8  2  3  1  7 
Linked List after Deletion at position 4: 
 8  2  3  1 
 
 
#include <stdio.h> 
#include <stdlib.h> 
#include<iostream>
using namespace std;
struct Node 
{ 
	int data; 
	struct Node *next; 
}; 
struct Node *newNode(int data) 
{ 
   Node *temp = new Node; 
   temp->data = data; 
   temp->next = NULL; 
   return temp; 
} 
void deleteNode(struct Node *head, int position) 
{ 
if (head == NULL) 
	return; 
struct Node* temp = head; 
	if (position == 0) 
	{ 
		head = temp->next; 
		free(temp);			
		return; 
	} 
	for (int i=0; temp!=NULL && i<position-1; i++) 
		temp = temp->next; 
	if (temp == NULL || temp->next == NULL) 
		return; 
	struct Node *next = temp->next->next; 
	free(temp->next); 
	temp->next = next;
} 
void printList(struct Node *node) 
{ 
	while (node != NULL) 
	{ 
		printf(" %d ", node->data); 
		node = node->next; 
	} 
} 
int main() 
 
{   int n;
    cin>>n;
	struct Node* head = NULL,*temp=NULL; 
   for(int i=0;i<n;i++)
    {
    int data;
    cin>>data;
    if(head==nullptr)
       head=temp=newNode(data);
    else
      {
      temp->next=newNode(data);
      temp=temp->next;
      } 
    }
	cout<<"Created Linked List: "; 
	printList(head); 
	deleteNode(head, 4); 
	cout<<"\nLinked List after Deletion at position 4: "; 
	printList(head); 
	return 0; 
} 
