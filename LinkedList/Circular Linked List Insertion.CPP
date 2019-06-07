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
void printList(char* msg, Node* head)
{
	cout << msg << ": ";
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
    int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
	for(int i=n-1;i>=0;i--){
		push(&head, num[i]);
	}
    printList("Original List:",head);
}
    
