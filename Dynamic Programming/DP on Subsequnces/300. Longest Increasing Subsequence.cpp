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

/*-----------------------------------------------------
Method 2: Trace Back LIS
  Time Complexity: O(n * n)
  Space Complexity: O(n)
--------------------------------------------------------*/

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1);
        int maxi = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[prev] < nums[i]){
                    dp[i] = max(1 + dp[prev], dp[i]);
                }
            }
            maxi = max(maxi, dp[i]);
        }
        return maxi;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-increasing-subsequence/description/
Author: M.R.Naganathan
*/
