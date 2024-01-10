/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
public:
    int pairSum(ListNode* head) {
        stack<int> nums;
        ListNode* curr = head;
        int size = 0, max_sum = INT_MIN, cnt = 0;
        while(curr != NULL){
            size++;
            curr = curr -> next;
        }
        curr = head;
        while(cnt != size/2){
            cnt += 1;
            nums.push(curr -> val);
            curr = curr -> next;
        }
        while(curr != NULL){
            if(max_sum < nums.top() + curr -> val){
                max_sum = nums.top() + curr -> val;
            }
            nums.pop();
            curr = curr -> next;
        }
        return max_sum;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-twin-sum-of-a-linked-list/
Author: M.R.Naganathan
*/
