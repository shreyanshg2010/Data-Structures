#include<bits/stdc++.h>
using namespace std;
struct Node{
    int data;
    Node* next;
};
void push(struct Node** head, int data)
{
	struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
	newNode->data = data;
	newNode->next = *head;
	*head = newNode;
}
void sorted(struct Node** head,struct Node* newnode){
    Node* dummy=new Node();
    Node* curr=dummy;
    dummy->next=*head;
    while(curr->next!=nullptr && curr->next->data<newnode->data)
        curr=curr->next;
    newnode->next=curr->next;
    curr->next=newnode;
    *head=dummy->next;
}
void InsertSort(Node** head){
    Node* result=nullptr;
    Node* curr=*head;
    Node* next;
    while(curr!=nullptr){
        next=curr->next;
        sorted(&result,curr);
        curr=next;
    }
    *head=result;
}

void printList(Node* head)
{
	 
        while (head != nullptr)
        {  
            cout << head->data << " ";  
            head = head->next;  
        }  
          
}    
int main(){
    Node* head=nullptr;
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
	for(int i=n-1;i>=0;i--){
		push(&head, num[i]);
	}
    //printList(head);
    InsertSort(&head);
    printList(head);
    
}
    
