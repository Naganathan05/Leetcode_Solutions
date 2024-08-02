/*-----------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
--------------------------------------*/

class Solution {
public:
    int Wiggle(vector<int> &nums, int i, int prevInd, int flag, vector<vector<vector<int>>> &dp){
        if(i == nums.size()) return 0;
        if(dp[i][prevInd + 1][flag] != -1) return dp[i][prevInd + 1][flag];

        int Pick = 0, noPick = 0;
        if(flag){
            if(prevInd == -1 || nums[i] - nums[prevInd] > 0) Pick = 1 + Wiggle(nums, i + 1, i, !flag, dp);
            noPick = Wiggle(nums, i + 1, prevInd, flag, dp);
        }
        else{
            if(prevInd == -1 || nums[i] - nums[prevInd] < 0) Pick = 1 + Wiggle(nums, i + 1, i, !flag, dp);
            noPick = Wiggle(nums, i + 1, prevInd, flag, dp);
        }
        return dp[i][prevInd + 1][flag] = max(Pick, noPick);
    }

    int wiggleMaxLength(vector<int>& nums) {
        vector<vector<vector<int>>> dp(nums.size(), vector<vector<int>> (nums.size() + 1, vector<int> (2, -1)));
        return max(Wiggle(nums, 0, -1, 0, dp), Wiggle(nums, 0, -1, 1, dp));
    }
};

/*
Question Link: https://leetcode.com/problems/wiggle-subsequence/
Author: M.R.Naganathan
*/
