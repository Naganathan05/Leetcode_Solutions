/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode *curr = list1;
        while(curr){
            if(curr -> val == a - 1){
                break;
            }
            curr = curr -> next;
        }
        ListNode *startNode = curr;
        curr = list1;
        while(curr){
            if(curr -> val == b + 1){
                break;
            }
            curr = curr -> next;
        }        
        ListNode *endNode = curr;
        startNode -> next = list2;
        curr = list2;
        while(curr -> next){
            curr = curr -> next;
        }
        curr -> next = endNode;
        return list1;
    }
};

/*
Question Link: https://leetcode.com/problems/merge-in-between-linked-lists/
Author: M.R.Naganathan
*/
