Input:1->2->3->4->5->6->7->8->NULL
Output:2->1->4->3->6->5->8->7->NULL



#include  <stdio.h>
#include<stdlib.h>
struct Node{
    int data;
    struct Node *next;
};
void push(struct Node** head,int data){
    struct Node* newnode=(struct Node*)malloc(sizeof(struct Node));
    newnode->data=data;
    newnode->next=*head;
    *head=newnode;
}
void printList(char *msg,struct Node* head){
    printf("%s:",msg);
    while(head){
        printf("%d->",head->data);
        head=head->next;
    }
    printf("NULL\n");
}
void rearrange(struct Node **head){
    while(*head==NULL || (*head)->next==NULL)
        return;
    struct Node* curr=*head,*prev=NULL;
    while(curr!=NULL && curr->next!=NULL){
        struct Node* tmp=curr->next;
        curr->next=tmp->next;
        tmp->next=curr;
        if(prev==NULL)
            *head=tmp;
        else
            prev->next=tmp;
        prev=curr;
        curr=curr->next;
    }
}
int main(void)
{
	int n;
    scanf("%d",&n);
    int arr[n];
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);

	struct Node *head = NULL;
	for (int i = n - 1; i >= 0; i--)
		push(&head, arr[i]);

	printList("Before", head);
	rearrange(&head);
	printList("After ", head);

	return 0;
}
        
