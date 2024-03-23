/*--------------------------------------
Method 1: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n) + O(n)
----------------------------------------*/

class Solution {
public:
    bool jump(vector<int> &nums, int i, vector<int> &dp){
        if(i == nums.size() - 1) return true;

        if(i > nums.size()) return false;

        if(dp[i] != -1) return dp[i];

        int maxJump = nums[i];
        bool result = false;
        for(int j = 1; j <= maxJump; j++){
            result = result || jump(nums, i + j, dp);
        }
        return dp[i] = result;
    }

    bool canJump(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0) return true;

        vector<int> dp(nums.size(), -1);
        return jump(nums, 0, dp);
    }
};

/*-----------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n)
--------------------------------------------------*/

class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size() == 1 && nums[0] == 0) return true;

        vector<bool> dp(nums.size(), false);
        dp[nums.size() - 1] = true;

        for(int i = nums.size() - 2; i >= 0; i--){
            bool result = false;
            for(int j = 1; j <= nums[i]; j++){
                if(i + j <= nums.size() - 1){
                    result = result || dp[i + j];
                }
            }
            dp[i] = result;
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/jump-game/description/
Author: M.R.Naganathan
*/
