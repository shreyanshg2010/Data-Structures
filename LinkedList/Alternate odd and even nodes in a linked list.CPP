Input : 11 -> 20 -> 40 -> 55 -> 77 -> 80 -> NULL
Output : 11 -> 20 -> 55 -> 40 -> 77 -> 80 -> NULL
20, 40, 80 occur in even positions and 11, 55, 77
occur in odd positions.

Input : 10 -> 1 -> 2 -> 3 -> 5 -> 6 -> 7 -> 8 -> NULL
Output : 1 -> 10 -> 3 -> 2 -> 5 -> 6 -> 7 -> 8 -> NULL
1, 3, 5, 7 occur in odd positons and 10, 2, 6, 8 occur
at even positions in the list


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
void rearrangeOddEven(Node* head) 
{ 
    stack<Node*> odd; 
    stack<Node*> even; 
    int i = 1; 
  
    while (head != nullptr) { 
  
        if (head->data % 2 != 0 && i % 2 == 0) { 
  
            // Odd Value in Even Position 
            // Add pointer to current node 
            // in odd stack 
            odd.push(head); 
        } 
  
        else if (head->data % 2 == 0 && i % 2 != 0) { 
  
            // Even Value in Odd Postion 
            // Add pointer to current node 
            // in even stack 
            even.push(head); 
        } 
  
        head = head->next; 
        i++; 
    } 
  
    while (!odd.empty() && !even.empty()) { 
        swap(odd.top()->data, even.top()->data); 
        odd.pop(); 
        even.pop(); 
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
rearrangeOddEven(head);
 printList(head);
	
	return 0; 
} 
