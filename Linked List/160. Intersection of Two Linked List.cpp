/*--------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------*/

class Solution {
public:
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*, int> freq;
        ListNode* curr = headA;
        while(curr){
            freq[curr] += 1;
            curr = curr -> next;
        }
        curr = headB;
        while(curr){
            if(freq[curr] > 0) freq[curr] = -999;
            curr = curr -> next;
        }
        curr = headA;
        while(curr){
            if(freq[curr] == -999) return curr;
            curr = curr -> next;
        }
        return NULL;
    }
};

/*
Question Link: https://leetcode.com/problems/intersection-of-two-linked-lists/
Author: M.R.Naganathan
*/
