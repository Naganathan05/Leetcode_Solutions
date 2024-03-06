/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    bool hasCycle(ListNode *head) {
        if (head == NULL || head->next == NULL) {
            return false;
        }

        ListNode *slow = head;
        ListNode *fast = head->next;

        while (fast != slow) {
            if (fast == NULL || fast->next == NULL) {
                return false;
            }
            slow = slow->next;
            fast = fast->next->next;
        }

        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/linked-list-cycle/description/?envType=daily-question&envId=2024-03-06
Author: M.R.Naganathan
*/
