/*-----------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
--------------------------------------*/

class Solution {
public:
    int integer(int n, int k, vector<vector<int>> &dp){
        if(n == 0 && k >= 2) return 1;
        if((n == 0 && k < 2) || n < 0) return 0;

        if(dp[n][k] != -1) return dp[n][k];

        int max_pro = 0;
        for(int i = 1; i <= n; i++){
            max_pro = max(max_pro, i * integer(n - i, k + 1, dp));
        }
        return dp[n][k] = max_pro;
    }

    int integerBreak(int n) {
        vector<vector<int>> dp(n + 1, vector<int> (n + 1, -1));
        return integer(n, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/integer-break/?envType=problem-list-v2&envId=m9p2qe8h
Author: M.R.Naganathan
*/
