Input:
8
1 2 3 4 5 6 7 8

Output:
before:1->2->3->4->5->6->7->8->null
After:2->4->6->8->1->3->5->7->null

#include  <stdio.h>
#include <stdlib.h>
struct Node{
    int data;
    struct Node* next;
};
void push(struct Node** head,int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
void printList(char* msg,struct Node* head){
    printf("%s:",msg);
    while(head){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("null\n");
}
void rearrangeEvenOdd(struct Node **head){
    struct Node *odd=NULL,*oddtail=NULL;
    struct Node *even=NULL,*eventail=NULL;
    struct Node *curr=*head;
    while(curr!=NULL)
    {
        if(curr->data & 1)
        {
            if(odd==NULL)
            {
                odd=oddtail=curr;
            }
            else
            {
                oddtail->next=curr;
                oddtail=oddtail->next;
            }
        }
        else{
            if(even==NULL){
                even=eventail=curr;
            }
            else{
                eventail->next=curr;
                eventail=eventail->next;
            }
        }
        curr=curr->next;
    }
    if(even){
        *head=even;
        eventail->next=odd;
    }
    else
        *head=odd;
    if(oddtail)
        oddtail->next=NULL;
}
int main(){
    struct Node* head=NULL;
    int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++){
        scanf("%d",&arr[i]);}
    for(int i=n-1;i>=0;i--){
        push(&head,arr[i]);
    }
    printList("before",head);
    rearrangeEvenOdd(&head);
    printList("After",head);
    return 0;
}
