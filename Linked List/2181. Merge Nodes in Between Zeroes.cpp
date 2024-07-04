/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr = head;
        ListNode* newcurr = head;
        ListNode* prev = head;
        curr = curr -> next;
        while(curr){
            int sum = 0;
            while(curr -> val != 0){
                sum += (curr -> val);
                curr = curr -> next;
            }
            newcurr -> val = sum;
            prev = newcurr;
            newcurr = newcurr -> next;
            curr = curr -> next;
        }
        prev -> next = NULL;
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
Author: M.R.Naganathan
*/
