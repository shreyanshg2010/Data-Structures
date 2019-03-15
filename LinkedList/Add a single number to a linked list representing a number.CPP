Original linked list: 9->9->9->9->3 
Digit:7
Resultant linked list:1->0->0->0->0->0


#include <stdio.h>
#include <stdlib.h>
struct Node
{
    int data;
    struct Node* next;
};
void push(struct Node** head, int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;

    *head = newNode;
}
void printList(char *msg, struct Node* head)
{
    printf("%s", msg);
    while (head)
    {
        printf("%d -> ", head->data);
        head = head->next;
    }

    printf("NULL\n");
}
int add(struct Node *head, int digit)
{
    // base case: end of the linked list is reached
    if (head == NULL)
        return digit;
    int carry = add(head->next, digit);
    //printf("%d\n",carry);
    if (carry == 0)
        return;
    int sum = head->data + carry;
    head->data = sum % 10;   
    return sum/10;          
}
void addDigit(struct Node** head, int digit){
    int carry = add(*head, digit);
    if (carry) {
        push(head, carry);
    }
}
int main()
{
    int n;
    scanf("%d",&n);
    int number[n];
    for(int i=0;i<n;i++)
        scanf("%d",&number[i]);

    struct Node *head = NULL;
    for (int i = n - 1; i >= 0; i--)
        push(&head, number[i]);

    int digit;
    scanf("%d",&digit);

   printList(" Original Linked List: ", head);
    addDigit(&head, digit);
    printList("Resultant Linked List: ", head);

    return 0;
}
