/*---------------------------------------
  Time Complexity: O(n * m * minProfit)
  Space Complexity: O(n * minProfit)
-------------------------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    int selectScheme(int n, int remProfit, int i, vector<int> &group, vector<int> &profit, vector<vector<vector<int>>> &dp) {
        if (i == group.size()) return (n >= 0 && remProfit <= 0);
        if (n < 0) return 0;
        
        remProfit = max(remProfit, 0);  
        if (dp[i][n][remProfit] != -1) return dp[i][n][remProfit];

        int Pick = selectScheme(n - group[i], remProfit - profit[i], i + 1, group, profit, dp);
        int noPick = selectScheme(n, remProfit, i + 1, group, profit, dp);
        return dp[i][n][remProfit] = (Pick + noPick) % mod;
    }

    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        vector<vector<vector<int>>> dp(group.size(), vector<vector<int>>(n + 1, vector<int>(minProfit + 1, -1)));
        return selectScheme(n, minProfit, 0, group, profit, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/profitable-schemes/description/
Author: M.R.Naganathan
*/
