/*---------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n) + O(n)
-----------------------------------------------*/

class Solution {
public:
    int f(vector<int> &nums, int i, vector<int> &dp){
        if(i == nums.size() - 1) return 0;

        if(i > nums.size() - 1) return 1e9;
        if(dp[i] != -1) return dp[i];

        int maxJump = nums[i];
        int min_jump = 1e9;
        for(int j = 1; j <= maxJump; j++){
            min_jump = min(min_jump, 1 + f(nums, i + j, dp));
        }
        return dp[i] = min_jump;
    }

    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(nums, 0, dp);
    }
};

/*-------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n* n)
  Space Complexity: O(n)
---------------------------------------------------*/

class Solution {
public:
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);    
        dp[nums.size() - 1] = 0;
        for(int i = nums.size() - 2; i >= 0; i--){
            int min_jump = 1e9;
            for(int j = 1; j <= nums[i]; j++){
                if(i + j <= nums.size() - 1) min_jump = min(min_jump, 1 + dp[i + j]);
            }
            dp[i] = min_jump;
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/jump-game-ii/description/
Author: M.R.Naganathan
*/
