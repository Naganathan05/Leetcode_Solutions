/*-----------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------------------*/

class Solution {
public:
    ListNode* doubleIt(ListNode* head) {
        head = reverse(head);
        ListNode* curr = head;
        ListNode* prev = NULL;
        int carry = 0;
        while(curr){
            prev = curr;
            int currVal = curr -> val;
            currVal = 2*currVal + carry;
            curr -> val = currVal % 10;
            carry = currVal/10;
            curr = curr -> next;
            if(!curr && carry){
                ListNode* newNode = new ListNode(carry);
                prev -> next = newNode;
            }
        }
        head = reverse(head);
        return head;
    }

    ListNode* reverse(ListNode* head){
        if(!head || !head -> next) return head;
        ListNode* curr = head;
        ListNode* prev = NULL;
        ListNode* nex = head;
        while(curr){
            nex = curr -> next;
            curr -> next = prev;
            prev = curr;
            curr = nex;
        }
        return prev;
    }
};

/*
Question Link: https://leetcode.com/problems/double-a-number-represented-as-a-linked-list/
Author: M.R.Naganathan
*/
