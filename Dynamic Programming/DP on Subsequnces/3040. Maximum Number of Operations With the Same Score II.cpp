/*------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
-------------------------------------*/

class Solution {
public:
    int operation(vector<int> &nums, int i, int j, int &requiredScore, vector<vector<int>> &dp) {
        if(i >= j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int firstSecond = 0, lastSecondLast = 0, firstLast = 0;

        if((j - i >= 1) && nums[i] + nums[i + 1] == requiredScore) firstSecond = 1 + operation(nums, i + 2, j, requiredScore, dp);
        if((j - i >= 1) && nums[j] + nums[j - 1] == requiredScore) lastSecondLast = 1 + operation(nums, i, j - 2, requiredScore, dp);
        if(nums[i] + nums[j] == requiredScore) firstLast = 1 + operation(nums, i + 1, j - 1, requiredScore, dp);
        return dp[i][j] = max({firstSecond, lastSecondLast, firstLast});
    }

    int maxOperations(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        int maxOperations = 1;
        
        int currOperationCount = 1;
        int requiredScore = nums[0] + nums[1];
        currOperationCount += operation(nums, 2, n - 1, requiredScore, dp);
        maxOperations = max(maxOperations, currOperationCount);

        dp.assign(n, vector<int> (n, -1));
        currOperationCount = 1;
        requiredScore = nums[n - 1] + nums[n - 2];
        currOperationCount += operation(nums, 0, n - 3, requiredScore, dp);
        maxOperations = max(maxOperations, currOperationCount);

        dp.assign(n, vector<int> (n, -1));
        currOperationCount = 1;
        requiredScore = nums[0] + nums[n - 1];
        currOperationCount += operation(nums, 1, n - 2, requiredScore, dp);
        maxOperations = max(maxOperations, currOperationCount);

        return maxOperations;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-operations-with-the-same-score-ii/
Author: M.R.Naganathan
*/
