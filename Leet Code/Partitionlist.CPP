Given a linked list and a value x, partition it such that all nodes less than x come before nodes greater than or equal to x.

You should preserve the original relative order of the nodes in each of the two partitions.

Example:

Input: head = 1->4->3->2->5->2, x = 3
Output: 1->2->2->4->3->5





class Solution {
public:
    ListNode* partition(ListNode* head, int x) {
      if(!head || !head->next ) return head  ;
        
        ListNode* left = new ListNode(0) ; 
        left->next = head ; 
        head = left   ; 
        
        ListNode* right = head;
        int countNodes = 0 ; 
        while( right->next )
        {
            countNodes++ ; 
            right = right->next ; 
        }
        
        while( countNodes )
        {
            if( left->next->val < x )
            {
                countNodes-- ; 
                left = left->next ; 
            }
            else
            {
                right->next = new ListNode(left->next->val); 
                right = right->next; 
                left->next = left->next->next ; 
                countNodes-- ; 
            }
        }
        
        return head->next ; 
    }
};
