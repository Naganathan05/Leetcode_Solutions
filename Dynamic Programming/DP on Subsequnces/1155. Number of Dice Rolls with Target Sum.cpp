/*--------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * k * target)
  Space Complexity: O(n * target) + O(target)
-----------------------------------------------*/

class Solution {
public:
    long mod = 1000000007;
    int Roll(int n, int k, int target, vector<vector<int>> &dp){
        if(target == 0 && !n) return 1;
        if(n == 0) return 0;

        if(dp[n][target] != -1) return dp[n][target];

        long tot_ways = 0;
        for(int i = 1; i <= k; i++){
            long ways = 0;
            if(target - i >= 0) ways = Roll(n - 1, k, target - i, dp);
            tot_ways += ways;
            tot_ways %= mod;
        }
        return dp[n][target] = tot_ways;
    }

    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, -1));
        return Roll(n, k, target, dp);
    }
};

/*-----------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * k * target)
  Space Complexity: O(n * k)
--------------------------------------------------*/

class Solution {
public:
    long mod = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<vector<int>> dp(n + 1, vector<int> (target + 1, 0));

        dp[0][0] = 1;
        for(int t = 1; t <= target; t++) dp[0][t] = 0;

        for(int i = 1; i <= n; i++){
            for(int t = 1; t <= target; t++){
                long tot_ways = 0;
                for(int j = 1; j <= k; j++){
                    long ways = 0;
                    if(t - j >= 0) ways = dp[i - 1][t - j];
                    tot_ways += ways;
                    tot_ways %= mod;
                }
                dp[i][t] = tot_ways;
            }
        }
        return dp[n][target];
    }
};

/*-------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * k * target)
  Space Complexity: O(target)
----------------------------------------------*/

class Solution {
public:
    long mod = 1000000007;
    int numRollsToTarget(int n, int k, int target) {
        vector<int> curr(target + 1, 0), prev(target + 1, 0);

        prev[0] = 1;
        for(int t = 1; t <= target; t++) prev[t] = 0;

        for(int i = 1; i <= n; i++){
            for(int t = 1; t <= target; t++){
                long tot_ways = 0;
                for(int j = 1; j <= k; j++){
                    long ways = 0;
                    if(t - j >= 0) ways = prev[t - j];
                    tot_ways += ways;
                    tot_ways %= mod;
                }
                curr[t] = tot_ways;
            }
            prev = curr;
        }
        return prev[target];
    
};

/*
Question Link: https://leetcode.com/problems/number-of-dice-rolls-with-target-sum/description/
Author: M.R.Naganathan
*/
