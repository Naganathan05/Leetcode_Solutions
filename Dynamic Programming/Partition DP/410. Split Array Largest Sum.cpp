/*--------------------------------
Method: Memoization
  Time Complexity: O(n * n * k)
  Space Complexity: O(n * k)
----------------------------------*/

class Solution {
public:
    int Split(vector<int> &nums, int i, int k, vector<vector<int>> &dp){
        if(i == nums.size()) return 1e9;

        if(k == 1 && i < nums.size()){
            int currSum = 0;
            for(int j = i; j <= nums.size() - 1; j++) currSum += nums[j];
            return dp[i][k] = currSum;
        }

        if(dp[i][k] != -1) return dp[i][k];

        int currSum = 0, minSum = 1e9;
        for(int j = i; j < nums.size(); j++){
            currSum += nums[j];
            minSum = min(minSum, max(currSum, Split(nums, j + 1, k - 1, dp)));
        }
        return dp[i][k] = minSum;
    }

    int splitArray(vector<int>& nums, int k) {
        vector<vector<int>> dp(nums.size(), vector<int> (k + 1, -1));
        return Split(nums, 0, k, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/split-array-largest-sum/
Author: M.R.Naganathan
*/
