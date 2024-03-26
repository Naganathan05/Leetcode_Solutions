/*------------------------------------------------
Method: Back Tarck LIS
  Time Complexity: O(n * n)
  Space Complexity: O(2*n)
---------------------------------------------------*/

class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(), 1), cnt(nums.size(), 1);
        int ans = 0, max_ele = 0;

        for(int i = 0; i <= nums.size() - 1; i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev] && dp[i] < dp[prev] + 1){
                    dp[i] = 1 + dp[prev];
                    cnt[i] = cnt[prev];
                }
                else if(nums[i] > nums[prev] && dp[i] == dp[prev] + 1){
                    cnt[i] += cnt[prev];
                }
            }
            max_ele = max(max_ele, dp[i]);
        }

        for(int i = 0; i <= nums.size() - 1; i++){
            if(dp[i] == max_ele) ans += cnt[i];
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-longest-increasing-subsequence/description/
Author: M.R.Naganathan
*/
