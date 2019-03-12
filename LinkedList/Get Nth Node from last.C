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
 cout<<"\nNth from last: ";
printNthFromLast(head,4);
	
	return 0; 
} 
