/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *dummy = new ListNode(-1);
        dummy -> next = head;
        ListNode *slowcurr = dummy;
        ListNode *fastcurr = dummy;
        for(int i = 0; i <= n; i++){
            fastcurr = fastcurr -> next;
        }
        while(fastcurr){
            fastcurr = fastcurr -> next;
            slowcurr = slowcurr -> next;
        }
        slowcurr -> next = (slowcurr -> next) -> next;
        return dummy -> next;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-nth-node-from-end-of-list/
Author: M.R.Naganathan
*/
