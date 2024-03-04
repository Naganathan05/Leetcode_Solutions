/*----------------------------------------------
Method 1: Memoization => Note: TLE :(
  Time Complexity: O(n*n)
  Space Complexity: O(n*n)
------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(vector<vector<int>> &matrix, int i, int j, vector<vector<int>> &dp){
        if(i == matrix.size() - 1) return matrix[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int left = INT_MAX, down = INT_MAX, right = INT_MAX;

        if(j - 1 >= 0) left = matrix[i][j] + recursiveFunction(matrix, i + 1, j - 1, dp);
        if(j + 1 <= matrix.size() - 1) right = matrix[i][j] + recursiveFunction(matrix, i + 1, j + 1, dp);
        down = matrix[i][j] + recursiveFunction(matrix, i + 1, j, dp);

        return dp[i][j] = min(min(left, right), down);
    }

    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), -1));
        int min_cost = INT_MAX;
        for(int i = 0; i <= matrix.size() - 1; i++){
            min_cost = min(min_cost, dp[0][i] = recursiveFunction(matrix, 0, i, dp));
        }
        return min_cost;
    }
};

/*---------------------------------------------------------
Method 2: Tabulation => Note: Recursive Stack Space Avoided
  Time Complexity: O(n*n)
  Space Complexity: O(n*n)
-----------------------------------------------------------*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int>(matrix.size(), 0));
        int min_cost = INT_MAX;
        for(int i = 0; i <= matrix.size() - 1; i++){
            dp[0][i] = matrix[0][i];
        }
        for(int i = 1; i <= matrix.size() - 1; i++){
            for(int j = 0; j <= matrix[i].size() - 1; j++){
                int left = INT_MAX, up = INT_MAX, right = INT_MAX;
                if(j - 1 >= 0) left = dp[i - 1][j - 1];
                if(j + 1 < matrix[i].size()) right = dp[i - 1][j + 1];
                up = dp[i - 1][j];
                dp[i][j] = matrix[i][j] + min(min(left, up), right);
            }
        }
        for(int i = 0; i <= matrix.size() - 1; i++){
            min_cost = min(min_cost, dp[matrix.size() - 1][i]);
        }
        return min_cost;
    }
};

/*----------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n*n)
  Space Complexity: O(n)
------------------------------------------------------*/

class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n, 0);
        vector<int> prev(n, 0);
        int min_cost = INT_MAX;
        for(int i = 0; i <= matrix.size() - 1; i++){
            dp[i] = matrix[0][i];
        }
        for(int i = 1; i <= n - 1; i++){
            prev = dp;
            for(int j = 0; j <= n - 1; j++){
                int left = INT_MAX, up = INT_MAX, right = INT_MAX;
                if(j - 1 >= 0) left = prev[j - 1];
                if(j + 1 < matrix[i].size()) right = prev[j + 1];
                up = prev[j];
                dp[j] = matrix[i][j] + min(min(left, up), right);
            }
        }
        for(int i = 0; i <= matrix.size() - 1; i++){
            min_cost = min(min_cost, dp[i]);
        }
        return min_cost;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-falling-path-sum/description/
Author: M.R.Naganathan
*/
