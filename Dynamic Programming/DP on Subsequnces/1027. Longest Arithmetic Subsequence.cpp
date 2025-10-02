/*-------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * diff)
----------------------------------*/

class Solution {
public:
    int longestArithSeqLength(vector<int>& nums) {
        int n = nums.size();
    
        vector<unordered_map<int, int>> dp(n);
        int maxLen = 1;

        for(int i = 0; i < n; i++) {
            for(int prev = 0; prev < i; prev++) {
                int currDiff = nums[i] - nums[prev];
                if(dp[i].find(currDiff) == dp[i].end()) dp[i][currDiff] = 2;
                dp[i][currDiff] = max(dp[i][currDiff], (dp[prev][currDiff] + 1));
                maxLen = max(maxLen, dp[i][currDiff]);
            }
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-arithmetic-subsequence/
Author: M.R.Naganathan
*/
