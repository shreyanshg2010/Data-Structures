#include<bits/stdc++.h> 
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
Node* removeDuplicates(struct Node *root) 
{ 
    struct Node *ptr1, *ptr2, *dup; 
    ptr1 = root; 
    while (ptr1 != NULL && ptr1->next != NULL) 
    { 
        ptr2 = ptr1; 
        while (ptr2->next != NULL) 
        {
            if (ptr1->data == ptr2->next->data) 
            { 
                dup = ptr2->next; 
                ptr2->next = ptr2->next->next; 
                delete(dup); 
            } 
            else 
                ptr2 = ptr2->next; 
        } 
        ptr1 = ptr1->next; 
    } 
    return root;
} 
void print(struct Node *node) 
{ 
    while (node != NULL) 
    { 
        printf("%d ", node->data); 
        node = node->next; 
    } 
} 
int main() 
{ 
    int T;
    cin>>T;
    while(T--)
    {
    int K;
    cin>>K;
    struct Node *head=nullptr;
    struct Node *temp=head;
    for(int i=0;i<K;i++)
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
    Node *result=removeDuplicates(head);
    print(result);
    cout<<"\n";
    }
    return 0; 
}
