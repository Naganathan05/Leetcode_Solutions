/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int n = nums.size();
        vector<int> nextGreater(n, -1);
        stack<int> filo;

        for(int i = 0; i < 2 * n; i++) {
            int num = nums[i % n];
            while(!filo.empty() && nums[filo.top()] < num) {
                nextGreater[filo.top()] = num;
                filo.pop();
            }

            if(i < n) filo.push(i);
        }
        return nextGreater;
    }
};

/*
Question Link: https://leetcode.com/problems/next-greater-element-ii/description/
Author: M.R.Naganathan
*/
