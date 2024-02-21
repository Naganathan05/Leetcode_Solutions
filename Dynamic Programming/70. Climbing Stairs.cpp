/*----------------------------------------------
Approach 1: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        for(int i = 0; i <= n; i++){
            dp[i] = -1;
        }
        return recursiveClimb(n, dp);
    }

    int recursiveClimb(int n, vector<int> &dp){

        if(dp[n] != -1){
            return dp[n];
        }

        if(n == 1 || n == 0){
            return 1;
        }
        
        dp[n] = recursiveClimb(n - 1, dp) + recursiveClimb(n - 2, dp);
        return dp[n];
    }
};



/*---------------------------------------------------------------
Approach 2: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------------------------*/

class Solution {
public:
    int climbStairs(int n) {
        vector<int> dp(n + 1);
        for(int i = 0; i <= n; i++){
            dp[i] = -1;
        }
        dp[0] = 1;
        dp[1] = 1;
        
        for(int i = 2; i <= n; i++){
            dp[i] = dp[i - 1] + dp[i - 2];
        }
        return dp[n];
    }
};

/*
Question Link: https://leetcode.com/problems/climbing-stairs/description/
Author: M.R.Naganathan
*/
