/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    int longestSubsequence(vector<int>& nums, int difference) {
        vector<int> dp(nums.size(), 1);
        unordered_map<int, int> mapping;
        int maxi = 1;
        
        for(int i = 0; i <= nums.size() - 1; i++) {
            int target = nums[i] - difference;
            if(mapping.find(target) != mapping.end()) dp[i] = max(dp[i], dp[mapping[target]] + 1);
            maxi = max(maxi, dp[i]);
            mapping[nums[i]] = i;
        }
        return maxi;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-arithmetic-subsequence-of-given-difference/
Author: M.R.Naganathan
*/
