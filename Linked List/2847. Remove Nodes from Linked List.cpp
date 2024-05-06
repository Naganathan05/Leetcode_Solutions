/*----------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------*/

class Solution {
public:
    ListNode* removeNodes(ListNode* head) {
        head = reverse(head);
        int curr_max = INT_MIN;
        ListNode* curr = head;
        ListNode* prev = head;
        while(curr){
            if(curr -> val < curr_max){
                prev -> next = curr -> next;
            }
            else{
                prev = curr;
            }
            curr_max = max(curr_max, curr -> val);
            curr = curr -> next;
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
Question Link: https://leetcode.com/problems/remove-nodes-from-linked-list/
Author: M.R.Naganathan
*/
