/*--------------------------------------
Method: Memoization
  Time Complexity: O(n * sqrt(n))
  Space Complexity: O(n) + O(n)
-----------------------------------------*/

class Solution {
public:
    int square(int n, vector<int> &dp){
        if(n == 0) return 0;

        if(n < 0) return 1e9;
        if(dp[n] != -1) return dp[n];

        int min_sq = 1e9;
        for(int i = 1; i*i <= n; i++){
            min_sq = min(min_sq, 1 + square(n - i*i, dp));
        }
        return dp[n] = min_sq;
    }

    int numSquares(int n) {
        vector<int> dp(n + 1, -1);
        return square(n, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/perfect-squares/
Author: M.R.Naganathan
*/
