/*----------------------------
Method: Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int maximumJumps(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> dp(n, -1);
        dp[0] = 0;
        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                if(abs(nums[i] - nums[prev]) > target || dp[prev] == -1) continue;
                dp[i] = max(dp[i], dp[prev] + 1);
            }
        }
        return dp[n - 1] == 0 ? -1 : dp[n - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-jumps-to-reach-the-last-index/
Author: M.R.Naganathan
*/
