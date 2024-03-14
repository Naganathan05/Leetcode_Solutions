/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------------------------*/

class Solution {
public:
    ListNode* swapNodes(ListNode* head, int k) {
        ListNode *slow = head;
        ListNode *fast = head;
        ListNode *curr = head;
        int temp = k;

        while(k != 1) {
            fast = fast -> next;
            k -= 1;
        }

        while(fast -> next){
            fast = fast -> next;
            slow = slow -> next;
        }

        while(temp != 1){
            temp -= 1;
            curr = curr -> next;
        }
        swap(curr -> val, slow -> val);
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/swapping-nodes-in-a-linked-list/
Author: M.R.Naganathan
*/
