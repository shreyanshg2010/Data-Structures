List before calling deleteAlt() 
1 2 3 4 5 
List after calling deleteAlt() 
1 3 5 


#include <stdio.h> 
#include <stdlib.h> 
#include<stack>
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
void deleteAlt(struct Node *head)  
{  
    if (head == NULL)  
        return;  
    struct Node *prev = head;  
    struct Node *node = head->next;  
  
    while (prev != NULL && node != NULL)  
    {  
        prev->next = node->next;  
        free(node);  
        prev = prev->next;  
        if (prev != NULL)  
            node = prev->next;  
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
 cout<<"\nList: ";
deleteAlt(head);
 printList(head);
	
	return 0; 
} 
