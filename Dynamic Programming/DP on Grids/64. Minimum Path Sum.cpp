/*----------------------------------------------
Method 1: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp){
        if(!i && !j) return grid[0][0];

        if(dp[i][j] != -1) return dp[i][j];

        int up_cost = INT_MAX, left_cost = INT_MAX;

        if(i - 1 >= 0) up_cost = grid[i][j] + recursiveFunction(grid, i - 1, j, dp);
        if(j - 1 >= 0) left_cost = grid[i][j] + recursiveFunction(grid, i, j - 1, dp);

        return dp[i][j] = min(up_cost, left_cost);
    }

    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));
        return recursiveFunction(grid, m - 1, n - 1, dp);
    }
};


/*---------------------------------------------------------
Method 2: Tabulation => Note: Recursive Stack Space Avoided
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------------------------------------*/

class Solution {
public:
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dp(m, vector<int> (n, -1));

        for(int i = 0; i <= m - 1; i++){
            for(int j = 0; j <= n - 1; j++){
                if(!i && !j) dp[i][j] = grid[0][0];
                else{
                    int up_cost = INT_MAX, left_cost = INT_MAX;
                    if(i - 1 >= 0) up_cost = grid[i][j] + dp[i - 1][j];
                    if(j - 1 >= 0) left_cost = grid[i][j] + dp[i][j - 1];
                    dp[i][j] = min(up_cost, left_cost);
                }
            }
        }
        return dp[m - 1][n - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-path-sum/description/
Author: M.R.Naganathan
*/
