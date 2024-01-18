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
        while(nex){
            if(curr -> val == (curr -> next) -> val){
                nex = curr -> next;
                while(nex -> val == curr -> val && nex){
                    nex = nex -> next;
                }
                prev -> next = nex;
                curr = nex;
            }
            else{

            }
            prev = curr;
            curr = nex;
            nex = nex -> next;
        }
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-duplicates-from-sorted-list-ii/description/
Author: M.R.Naganathan
*/
