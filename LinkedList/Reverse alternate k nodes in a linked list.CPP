#include <iostream>
using namespace std;
struct Node {
	int data;
	Node* next;
	Node(int data)
	{
		this->data = data;
		this->next = nullptr;
	}
};
void push(Node* &head, int data)
{
	Node* node = new Node(data);
	node->next = head;
	head = node;
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
Node* reverse(Node*& curr, int k)
{
	Node* prev = nullptr;
	while (curr && k--) {
		Node* temp = curr->next;
		curr->next = prev;
		prev = curr;
		curr = temp;
	}
	return prev;
}
Node* skipKNodes(Node*& curr, int k)
{
	Node* prev = nullptr;

	while (curr && k--) {
		prev = curr;
		curr = curr->next;
	}

	return prev;
}
Node* reverseAlternatingKNodes(Node* head, int k)
{
	Node* prev = nullptr;
	Node* curr = head;
    int c=0;
	while (curr)
	{
		Node* lastNode = curr;
		Node* frontNode = reverse(curr, k);
		if (prev==nullptr) {
			head = frontNode;
		}
		else {
			prev->next = frontNode;
		}
		lastNode->next = curr;
		prev = skipKNodes(curr, k);
	}
	return head;
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
	int k ;
    cin>>k;
	printList("Original Linked List ", head);
	head = reverseAlternatingKNodes(head, k);
	printList("Resultant Linked List", head);
	return 0;
}
