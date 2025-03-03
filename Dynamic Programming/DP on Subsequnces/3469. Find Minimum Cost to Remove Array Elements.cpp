/*-----------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
-------------------------------------*/

class Solution {
public:
    int calculateCost(vector<int> &nums, int i, int j, vector<vector<int>> &dp){
        if(j == nums.size()) return nums[i];

        if(dp[i][j] != -1) return dp[i][j];

        int firstNum = nums[i], secondNum = nums[j];
        if(j + 1 == nums.size()) return max(firstNum, secondNum);
        int thirdNum = nums[j + 1];

        int firstPick = max(firstNum, secondNum) + calculateCost(nums, j + 1, j + 2, dp);
        int secondPick = max(secondNum, thirdNum) + calculateCost(nums, i, j + 2, dp);
        int thirdPick = max(firstNum, thirdNum) + calculateCost(nums, j, j + 2, dp);
        return dp[i][j] = min({firstPick, secondPick, thirdPick});
    }

    int minCost(vector<int>& nums) {
        int n = nums.size();
        if(n == 1) return nums[0];
        vector<vector<int>> dp(n, vector<int> (n, -1));
        return calculateCost(nums, 0, 1, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/find-minimum-cost-to-remove-array-elements/
Author: M.R.Naganathan
*/
