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
bool ispalindrome(Node *head){
    stack<int> s;
    Node* temp=head;
    while(temp){
        s.push(temp->data);
        temp=temp->next;}
    temp=head;
    while(temp){
        int top=s.top();
        s.pop();
        if(top!=temp->data)
            return false;
        temp=temp->next;}
    return true;
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
    if(ispalindrome(head))
        cout<<"palindrome";
    else
        cout<<"not palindrome";
    
    return 0;
}
