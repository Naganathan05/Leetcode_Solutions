/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexty: O(1)
-------------------------------------------------*/

class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(!head -> next){
            return NULL;
        }
        ListNode *fast = head;
        ListNode *slow = head;
        ListNode *prev = head;
        while(fast && fast -> next){
            fast = (fast -> next) -> next;
            prev = slow;
            slow = slow -> next;
        }
        prev -> next = slow -> next;
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/delete-the-middle-node-of-a-linked-list/
Author: M.R.Naganathan
*/
