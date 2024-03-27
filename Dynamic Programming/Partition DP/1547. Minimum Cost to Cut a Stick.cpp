/*-------------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n) + O(n)
----------------------------------------------------*/

class Solution {
public:
    int Cost(vector<int> &cuts, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int mini = INT_MAX;
        for(int k = i; k <= j; k++){
            int cost = (cuts[j + 1] - cuts[i - 1]) + Cost(cuts, i, k - 1, dp) + Cost(cuts, k + 1, j, dp);
            mini = min(mini, cost);
        }
        return dp[i][j] = mini;
    }

    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), -1));
        return Cost(cuts, 1, m, dp);
    }
};

/*----------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n)
-------------------------------------------------------*/

class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        vector<vector<int>> dp(cuts.size(), vector<int> (cuts.size(), 0));

        for(int i = m; i >= 1; i--){
            for(int j = i; j <= m; j++){
                int mini = INT_MAX;
                for(int k = i; k <= j; k++){
                    int cost = (cuts[j + 1] - cuts[i - 1]) + dp[i][k - 1] + dp[k + 1][j];
                    mini = min(mini, cost);
                }
                dp[i][j] = mini;
            }
        }
        return dp[1][m];
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-cost-to-cut-a-stick/description/
Author: M.R.Naganathan
*/
