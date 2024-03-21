/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
-------------------------------------------------*/

class Solution {
public:
    int recursion(int n, vector<int> &dp){
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;

        if(dp[n] != -1) return dp[n];

        return dp[n] = recursion(n - 1, dp) + recursion(n - 2, dp) + recursion(n - 3, dp);
    }

    int tribonacci(int n) {
        vector<int> dp(n + 1, -1);
        return recursion(n, dp);
    }
};

/*--------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------------------*/

class Solution {
public:
    int tribonacci(int n) {
        if(n == 0) return 0;
        if(n == 1 || n == 2) return 1;
        vector<int> dp(n + 1, 0);
        dp[0] = 0;
        dp[1] = dp[2] = 1;
        for(int i = 3; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2] + dp[i - 3];
        }
        return dp[n];
    }
};

/*
Question Link: https://leetcode.com/problems/n-th-tribonacci-number/description/
Author: M.R.Naganathan
*/
