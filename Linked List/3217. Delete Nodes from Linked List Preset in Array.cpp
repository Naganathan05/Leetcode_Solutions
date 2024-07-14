/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    ListNode* modifiedList(vector<int>& nums, ListNode* head) {
        unordered_map<int, int> freq;
        for(int i : nums) freq[i] += 1;

        ListNode* curr = head;
        ListNode* prev = NULL;
        while(curr){
            if(freq[curr -> val] > 0){
                if(curr == head){
                    head = head -> next;
                    curr = head;
                    continue;
                }
                else{
                    prev -> next = curr -> next;
                    curr = curr -> next;
                    continue;
                }
            }
            prev = curr;
            curr = curr -> next;
        }
        return head;
    }
};

/*
Question Link: https://leetcode.com/problems/delete-nodes-from-linked-list-present-in-array/
Author: M.R.Naganathan
*/
