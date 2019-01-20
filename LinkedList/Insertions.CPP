
#include <iostream>
using namespace std;
struct node{
int data;
struct node* next;
};
//insert at the beginning
void push(struct node** head,int new_data){
    struct node* new_node=(struct node*) malloc(sizeof(struct node));
    new_node->data=new_data;
    new_node->next=*head;
    *head=new_node;}
 //insert after a node
void insertafter(struct node* prev,int new_data){
    if(prev->next==NULL){
        cout<<"Previous next is null";
        return;}
    struct node* new_node =(struct node*) malloc(sizeof(struct node)); 
    new_node->data=new_data;
    new_node->next=prev->next;
    prev->next=new_node;}
  //insert at the end
void pushatlast(struct node** head,int new_data){
    struct node* new_node =(struct node*) malloc(sizeof(struct node)); 
    struct node *last = *head;
    new_node->data=new_data;
    new_node->next=NULL;
    if(*head == NULL){
        *head = new_node; 
        return; }
    while (last->next != NULL) 
        last = last->next;
    last->next=new_node;
        
    }
   //print the list
void printList(struct node *node) {
    while (node != NULL) {
     printf(" %d ", node->data); 
        node = node->next; }
} 
int main() 
{ 
  struct node* head = NULL; 
  pushatlast(&head, 6); 
  push(&head, 7); 
  push(&head, 1); 
  pushatlast(&head, 4);
  insertafter(head->next, 8); 
  printf("\n Created Linked list is: "); 
  printList(head); 
  
  return 0; 
} 
