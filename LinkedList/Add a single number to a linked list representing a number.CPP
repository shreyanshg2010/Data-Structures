Original linked list: 9->9->9->9->3 
Digit:7
Resultant linked list:1->0->0->0->0->0


#include <stdio.h>
#include <stdlib.h>

// Data Structure to store a linked list node
struct Node
{
    int data;
    struct Node* next;
};

// Helper function to create a new node of the linked list
struct Node* newNode(int data)
{
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;

    return newNode;
}

// Helper function to print given linked list
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

// Function to reverse the given linked list
void reverse(struct Node** head)
{
    struct Node* prev = NULL;
    struct Node* current = *head;
    struct Node* next;

    // traverse the list
    while (current)
    {
        // tricky: note the next node
        next = current->next;

        // fix the current node
        current->next = prev;

        // advance the two pointers
        prev = current;
        current = next;
    }

    // fix the head pointer to point to the new front
    *head = prev;
}

// Function to add a single-digit number to a singly linked list 
// whose nodes represents digits of a number
void addDigit(struct Node** head, int digit)
{
    // empty list
    if (*head == NULL)
        return;

    // reverse the linked list
    reverse(head);

    // initialize carry with given digit
    int carry = digit;

    // traverse the reversed list
    struct Node* curr = *head;
    while (carry)
    {
        // get sum of current node and carry
        int sum = curr->data + carry;

        // update value of the current node with the single-digit sum
        curr->data = sum % 10;

        // set carry for the next node
        carry = sum / 10;

        // break if current node is the last node
        if (curr->next == NULL)
            break;

        // move to the next node
        curr = curr->next;
    }

    // add a new node at the end of linked list if there is any carry left
    if (carry)
        curr->next = newNode(carry);

    // reverse the list again to restore the original order
    reverse(head);
}

// main function
int main(void)
{
    struct Node *head = newNode(9);
    head->next = newNode(9);
    head->next->next = newNode(9);
    head->next->next->next = newNode(9);
    head->next->next->next->next = newNode(3);

    int digit = 7;

    printList(" Original Linked List: ", head);
    addDigit(&head, digit);
    printList("Resultant Linked List: ", head);

    return 0;
}
