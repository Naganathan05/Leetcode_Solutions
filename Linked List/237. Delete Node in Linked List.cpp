/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    void deleteNode(ListNode* node) {
        ListNode *curr = node;
        ListNode *prev = node;
        while (curr -> next){
            prev = curr;
            curr -> val = (curr -> next) -> val;
            curr = curr -> next;
        }
        prev -> next = NULL;
    }
};

/*
Question Link: https://leetcode.com/problems/delete-node-in-a-linked-list/
Author: M.R.Naganathan
*/
