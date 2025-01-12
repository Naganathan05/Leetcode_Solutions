/*------------------------------------------
  Time Complexity: O(m * n * k)
  Space Complexty: O(m * n * k) + O(m * n)
--------------------------------------------*/

class Solution {
public:
    int dfs(int i, int j, int k, vector<vector<int>>& coins, vector<vector<vector<int>>>& dp) {
        int m = coins.size(), n = coins[0].size();

        if (i >= m || j >= n) return -1e9;

        if (i == m - 1 && j == n - 1) {
            if (coins[i][j] >= 0) return coins[i][j];
            if (k > 0) return 0;
            return coins[i][j];
        }

        if (dp[i][j][k] != -1) return dp[i][j][k];

        int currentValue = coins[i][j];
        int maxProfit = -1e9;

        if (currentValue < 0) {
            if (k > 0) {
                maxProfit = max(maxProfit, dfs(i + 1, j, k - 1, coins, dp));
                maxProfit = max(maxProfit, dfs(i, j + 1, k - 1, coins, dp));
            }
            maxProfit = max(maxProfit, dfs(i + 1, j, k, coins, dp) + currentValue);
            maxProfit = max(maxProfit, dfs(i, j + 1, k, coins, dp) + currentValue);
        } 
        else {
            maxProfit = max(maxProfit, dfs(i + 1, j, k, coins, dp) + currentValue);
            maxProfit = max(maxProfit, dfs(i, j + 1, k, coins, dp) + currentValue);
        }
        return dp[i][j][k] = maxProfit;
    }

    int maximumAmount(vector<vector<int>>& coins) {
        int m = coins.size(), n = coins[0].size();
        vector<vector<vector<int>>> dp(m, vector<vector<int>>(n, vector<int>(3, -1)));
        return dfs(0, 0, 2, coins, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-amount-of-money-robot-can-earn/
Author: M.R.Naganathan
*/
