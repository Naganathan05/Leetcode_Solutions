/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------------------*/

class Solution {
public:
    ListNode* mergeNodes(ListNode* head) {
        ListNode *curr = head;
        ListNode *newhead = NULL;
        ListNode *newcurr = newhead;
        int sum = 0, cnt = 0;
        while(curr){
            if(curr -> val == 0){
                cnt += 1;
            }

            if(cnt != 2){
                sum += curr -> val;
            }
            else{
                cnt = 1;
                ListNode *newNode = new ListNode(sum);
                if(newcurr != NULL){
                    newcurr -> next = newNode;
                    newcurr = newNode;
                }
                else{
                    newcurr = newNode;
                    newhead = newNode;
                }
                sum = 0;
            }
            curr = curr -> next;
        }
        return newhead;
    }
};

/*
Question Link: https://leetcode.com/problems/merge-nodes-in-between-zeros/
Author: M.R.Naganathan
*/
