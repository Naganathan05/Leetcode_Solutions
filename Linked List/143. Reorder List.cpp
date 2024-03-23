/*--------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------------------------*/

class Solution {
public:
    void reorderList(ListNode* head) {
        if (!head || !head->next || !head->next->next) return;
        ListNode* curr = head;
        ListNode* fast = head;
        ListNode* prev = NULL;

        while(fast && fast -> next){
            fast = (fast -> next) -> next;
            prev = curr;
            curr = curr -> next;
        }
        prev -> next = NULL;
        curr = reverse(curr);
        ListNode* newCurr = head, *temp;
        bool flag = 1;
        while(newCurr && curr){
            if(flag){
                temp = newCurr -> next;
                newCurr -> next = curr;
                newCurr = temp;
                flag = 0;
            }
            else{
                temp = curr -> next;
                curr -> next = newCurr;
                curr = temp;
                flag = 1;
            }
        }
    }

    ListNode* reverse(ListNode* head){
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
Question Link: https://leetcode.com/problems/reorder-list/description/
Author: M.R.Naganathan
*/
