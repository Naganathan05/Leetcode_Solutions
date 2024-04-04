/*--------------------------------------------
Method 1: Memoization 
  Time Complexity: O(n * target)
  Space Complexity: O(n * target) + O(target)
----------------------------------------------*/

class Solution {
public:
    int f(vector<int> &nums, int i, int target, vector<vector<int>> &dp){
        if(target == 0) return 0;
        if(target < 0) return -1e9;
        if(i < 0 && target > 0) return -1e9;

        if(dp[i][target] != -1) return dp[i][target];

        int Pick = INT_MIN, noPick;
        if(target >= nums[i]) Pick = 1 + f(nums, i - 1, target - nums[i], dp);
        noPick = f(nums, i - 1, target, dp);
        return dp[i][target] = max(Pick, noPick);
    }

    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, -1));
        int len = f(nums, nums.size() - 1, target, dp);
        if(len < 0) return -1;
        return len;
    }
};

/*----------------------------------
Method 2: Tabulation
  Time Complexity: O(n * target)
  Space Complexity: O(n * target)
------------------------------------*/

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<vector<int>> dp(nums.size(), vector<int> (target + 1, 0));

        for(int i = 0; i <= nums.size() - 1; i++) dp[i][0] = 0;
        for(int i = 1; i <= target; i++){
            if(i - nums[0] == 0) dp[0][i] = 1;
            else dp[0][i] = -1e9;
        }

        for(int i = 1; i <= nums.size() - 1; i++){
            for(int j = 1; j <= target; j++){
                int Pick = INT_MIN, noPick;
                if(j >= nums[i]) Pick = 1 + dp[i - 1][j - nums[i]];
                noPick = dp[i - 1][j];
                dp[i][j] = max(Pick, noPick);
            }
        }
        int len = dp[nums.size() - 1][target];
        if(len < 0) return -1;
        return len;
    }
};

/*--------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * target)
  Space Complexity: O(target)
-----------------------------------------*/

class Solution {
public:
    int lengthOfLongestSubsequence(vector<int>& nums, int target) {
        vector<int> prev(target + 1, 0), curr(target + 1, 0);

        curr[0] = 0;
        for(int i = 1; i <= target; i++){
            if(i - nums[0] == 0) curr[i] = 1;
            else curr[i] = -1e9;
        }

        for(int i = 1; i <= nums.size() - 1; i++){
            prev = curr;
            for(int j = 1; j <= target; j++){
                int Pick = INT_MIN, noPick;
                if(j >= nums[i]) Pick = 1 + prev[j - nums[i]];
                noPick = prev[j];
                curr[j] = max(Pick, noPick);
            }
        }
        int len = curr[target];
        if(len < 0) return -1;
        return len;
    }
};

/*
Question Link: https://leetcode.com/problems/length-of-the-longest-subsequence-that-sums-to-target/description/
Author: M.R.Naganathan
*/
