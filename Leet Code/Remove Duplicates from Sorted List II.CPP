Input: 1->2->3->3->4->4->5
Output: 1->2->5


Input: 1->1->1->2->3
Output: 2->3


ListNode* deleteDuplicates(ListNode* head) {
        ListNode* temp=new ListNode(0);
        temp->next=head;
        ListNode* curr=head;
        ListNode* prev=temp;
        while(curr!=nullptr){
            while(curr->next!=nullptr && prev->next->val==curr->next->val){
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
        head=temp->next;
        return head;
    }
