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
int GetNth(Node* head, int index)  
{  
      
    Node* current = head; 
    int count = 0;  
    while (current != NULL)  
    {  
        if (count == index)  
            return(current->data);  
        count++;  
        current = current->next;  
    }  
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
 cout<<"\nNth: ";
cout<<GetNth(head,3);
	
	return 0; 
} 
