/*-------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
----------------------------------*/

class Solution {
public:
    int recursiveFunction(vector<int> &nums, int ind, vector<int> &dp, int start){
        if(ind == start) return nums[ind];
        if(ind < start) return 0;

        if(dp[ind] != -1) return dp[ind];

        int Take = nums[ind] + recursiveFunction(nums, ind - 2, dp, start);
        int noTake = recursiveFunction(nums, ind - 1, dp, start);
        return dp[ind] = max(Take, noTake);
    }

    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        vector<int> dp1(nums.size(), -1);
        int case1 = recursiveFunction(nums, nums.size() - 2, dp1, 0);

        vector<int> dp2(nums.size(), -1);
        int case2 = recursiveFunction(nums, nums.size() - 1, dp2, 1);
        return max(case1, case2);
    }
};

/*
Question Link: https://leetcode.com/problems/house-robber-ii/
Author: M.R.Naganathan
*/
