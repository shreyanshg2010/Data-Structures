#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void push(struct Node **head,int data){
    Node* newnode=new Node();
    Node* temp=*head;
    newnode->data=data;
    newnode->next=*head;
    if(*head!=NULL){
        while(temp->next!=*head)
            temp=temp->next;
        temp->next=newnode;
    }
    else
        newnode->next=newnode;
    *head=newnode;
}
void splitList(struct Node *head, struct Node **head1,  
                                            struct Node **head2) 
{ 
  struct Node *slow_ptr = head; 
  struct Node *fast_ptr = head;  
  if(head == NULL) 
    return; 
  while(fast_ptr->next != head && 
         fast_ptr->next->next != head)  
  { 
     fast_ptr = fast_ptr->next->next; 
     slow_ptr = slow_ptr->next; 
  } 
  if(fast_ptr->next->next == head) 
    fast_ptr = fast_ptr->next;
  *head1 = head;
  if(head->next != head) 
    *head2 = slow_ptr->next;   
  fast_ptr->next = slow_ptr->next;  
  slow_ptr->next = head;        
} 
void printList(Node* head)
{
	
	Node *temp = head;  
    if (head != NULL)  
    {  
        do
        {  
            cout << temp->data << " ";  
            temp = temp->next;  
        }  
        while (temp != head);  
    }  
	//cout <<"null"<<'\n';
}    
int main(){
    Node* head=nullptr;
    Node *head1 = NULL; 
    Node *head2 = NULL; 
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
	for(int i=n-1;i>=0;i--){
		push(&head, num[i]);
	}
    printList(head);
    splitList(head, &head1, &head2); 
    printf("\nFirst Circular Linked List"); 
    printList(head1);   
  
    printf("\nSecond Circular Linked List"); 
    printList(head2);   
    
}
    
