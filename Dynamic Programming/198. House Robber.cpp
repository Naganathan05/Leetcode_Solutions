/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------------------------*/

class Solution {
public:

    int recursiveFunction(vector<int> &nums, int ind, vector<int> &dp){

        if(ind == 0) return nums[ind];
        if(ind < 0) return 0;

        if(dp[ind] != -1) return dp[ind];

        int Pick = nums[ind] + recursiveFunction(nums, ind - 2, dp);
        int noPick = recursiveFunction(nums, ind - 1, dp);
        return dp[ind] = max(Pick, noPick);
    }
    
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return recursiveFunction(nums, nums.size() - 1, dp);
    }
};

/*-------------------------------------------------------------
Method 2: Tabulation => Note: No Recursion Stack Space Required
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------------------------------*/

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        dp[0] = nums[0];
        for(int i = 1; i <= nums.size() - 1; i++){
            int Take = nums[i];
            if(i - 2 >= 0) Take += dp[i - 2];
            int noTake = dp[i - 1];
            dp[i] = max(Take, noTake);
        }
        return dp[nums.size() - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/house-robber/
Author: M.R.Naganathan
*/
