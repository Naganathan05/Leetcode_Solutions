/*----------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------------------*/

class Solution {
public:
    int recursion(vector<int> &nums, int i, int prevInd, vector<vector<int>> &dp){
        if(i == nums.size()) return 0;

        if(dp[i][prevInd + 1] != -1) return dp[i][prevInd + 1];

        if(prevInd == -1 || nums[prevInd] < nums[i]){
            return dp[i][prevInd + 1] = max(1 + recursion(nums, i + 1, i, dp), recursion(nums, i + 1, prevInd, dp));
        }
        return dp[i][prevInd + 1] = recursion(nums, i + 1, prevInd, dp);
    }

    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>> dp(nums.size(), vector<int> (nums.size() + 1, -1));
        return recursion(nums, 0, -1, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
Author: M.R.Naganathan
*/
