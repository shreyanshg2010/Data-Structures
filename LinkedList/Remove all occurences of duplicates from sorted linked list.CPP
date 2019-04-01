#include <iostream>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node* next;
    Node(int data){
        this->data=data;
        this->next=nullptr;
    }
};
void push(Node* &head,int data){
    Node* newnode=new Node(data);
    newnode->next=head;
    head=newnode;
}
void printList(char* msg, Node* head)
{
	cout << msg << ": ";
	while (head) {
		cout << head->data << " -> ";
		head = head->next;
	}
	cout << "null" << '\n';
}
void deleteDuplicates(Node* A) {
    Node* dummy=new Node(0);
    dummy->next=A;
    Node* prev=dummy;
    Node* curr=A;
    while(curr!=nullptr){
        while(curr->next!=nullptr && prev->next->data==curr->next->data){
            curr=curr->next;
        }
        if(prev->next==curr){
            prev=prev->next;
        }
        else{
            prev->next=curr->next;
        }
        curr=curr->next;
    }
    A=dummy->next;
   // return A;
}
int main()
{
	Node* head = nullptr;
	int n;
    cin>>n;
    int num[n];
    for(int i=0;i<n;i++)
        cin>>num[i];
	for(int i=n-1;i>=0;i--){
		push(head, num[i]);
	}
    printList("Original List:",head);
    deleteDuplicates(head);
    printList("List:",head);
    return 0;
}
