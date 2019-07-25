    You are given two non-empty linked lists representing two non-negative integers. The digits are stored in reverse order and each of their nodes contain a single digit. Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, except the number 0 itself.

Example:

Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.



ListNode* addTwoNumbers(ListNode* l1, ListNode* l2, const int & carry = 0) {
              if(!l1 && !l2 && !carry) return NULL;
        
        int v1 = l1 ? l1->val : 0;
        int v2 = l2 ? l2->val : 0;
        int sum = (v1 + v2 + carry) % 10;
        int nC = (v1 + v2 + carry) / 10;
        
        ListNode * cur = new ListNode(sum);
        cur->next = addTwoNumbers(l1 ? l1->next : NULL, l2 ? l2->next : NULL, nC);
        return cur;
        }
