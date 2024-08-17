/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    long long Alternate(vector<int> &nums, int i, int sign, vector<vector<long long>> &dp) {
        if (i == nums.size()) return 0;

        if (dp[i][sign] != -1) return dp[i][sign];

        long long Pick = 0;
        if (sign == 0) Pick = nums[i] + Alternate(nums, i + 1, !sign, dp);
        else Pick = -nums[i] + Alternate(nums, i + 1, !sign, dp);

        long long noPick = Alternate(nums, i + 1, sign, dp);
        return dp[i][sign] = max(Pick, noPick);
    }

    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>> dp(nums.size(), vector<long long>(2, -1));
        return Alternate(nums, 0, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-alternating-subsequence-sum/
Author: M.R.Naganathan
*/
