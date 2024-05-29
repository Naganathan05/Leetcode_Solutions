/*---------------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
------------------------------------------*/

class Solution {
public:
    int recursion(int n, vector<int> &dp){
        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;

        if(dp[n] != -1) return dp[n];

        dp[n] = (((recursion(n - 1, dp) % 1000000007) * 2) % 1000000007 + (recursion(n - 3, dp) % 1000000007)) % 1000000007;
        return dp[n];
    }

    int numTilings(int n) {
        vector<int> dp(n + 1, -1);
        return recursion(n, dp);
    }
};

/*-------------------------------------------
Method: Tabulation  
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------------*/

class Solution {
public:
    int numTilings(int n) {

        if(n == 1) return 1;
        if(n == 2) return 2;
        if(n == 3) return 5;

        vector<int> dp(n + 1, 0);
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 5;

        for(int i = 4; i <= n; i++) dp[i] = (((dp[i - 1] % 1000000007) * 2) % 1000000007 + (dp[i - 3] % 1000000007) % 1000000007) % 1000000007;
        return dp[n];
    }
};

/*
Question Link: https://leetcode.com/problems/domino-and-tromino-tiling/
Author: M.R.Naganathan
*/
