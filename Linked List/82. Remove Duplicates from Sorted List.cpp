/*---------------------------------------------------------------
  Time Complexity: O(n)  =>  n:Number of Nodes in the Linked List
  Space Complexity: O(n) 
-----------------------------------------------------------------*/

class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(!head || !head -> next){
            return head;
        }
        ListNode* curr = head;
        ListNode* prev = head;
        ListNode* nex = head;
        map<int, int> freq;
        while(curr){
            freq[curr -> val]++;
            curr = curr -> next;
        }
        curr = head;
        while(curr){
            if(freq[curr -> val] > 1){
                prev -> next = curr -> next;
                curr = prev -> next;
            }
            else{
                prev = curr;
                curr = curr -> next;
            }
        }
        if(freq[head -> val] > 1){
            head = head -> next;
        }
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
Author: M.R.Naganathan
*/
