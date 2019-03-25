Input:
8
1 2 3 4 5 6 7 8
2

Output:
before:1->2->3->4->5->6->7->8->null
After:1->7->3->4->5->6->2->8->null


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
void swapnodes(struct Node **head,int k){
    struct Node *x,*y,*x_prev=NULL,*y_prev=*head;
    struct Node* curr=*head;
    for(int i=1;i<k && curr;i++){
        x_prev=curr;
        curr=curr->next;}
    x=curr;
    if(curr==NULL)
        return;
    struct Node* ptr=*head;
    while(curr->next){
        y_prev=ptr;
        ptr=ptr->next;
        curr=curr->next;
    }
    y=ptr;
    
    if(x->next==y){
        x->next=y->next;
        y->next=x;
        x_prev->next=y;
    }
    else if(y->next==x){
        y->next=x->next;
        x->next=y;
        y_prev->next=x;
    }
    else if(x==*head){
        *head=y;
        y->next=x->next;
        y_prev->next=x;
        x->next=NULL;
    }
    else if(y==*head){
        *head=x;
        x->next=y->next;
        x_prev->next=y;
        y->next=NULL;
    }
    else{
        ptr=y->next;
        y->next=x->next;
        x->next=ptr;
        
        x_prev->next=y;
        y_prev->next=x;
    }
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
    int k;
    scanf("%d",&k);
    swapnodes(&head,k);
    printList("After",head);
    return 0;
}
