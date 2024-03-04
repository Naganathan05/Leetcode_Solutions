/*----------------------------------------------
Method 1: Memoization
  Time Complexity: O(n*n)
  Space Complexity: O(n*n)
-----------------------------------------------*/

class Solution {
public:
    int recursiveFunction(vector<vector<int>> &triangle, int i, int j, vector<vector<int>> &dp){
        if(i == triangle.size() - 1) return triangle[i][j];

        if(dp[i][j] != -1) return dp[i][j];

        int down, right_down;

        down = triangle[i][j] + recursiveFunction(triangle, i + 1, j, dp);
        right_down = triangle[i][j] + recursiveFunction(triangle, i + 1, j + 1, dp);

        return dp[i][j] = min(down, right_down);
    }

    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), -1));
        return recursiveFunction(triangle, 0, 0, dp);
    }
};


/*---------------------------------------------------------
Method 2: Tabulation => Note: Recursive Stack Space Avoided
  Time Complexity: O(n*n)
  Space Complexity: O(n*n)
-----------------------------------------------------------*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle.size(), vector<int> (triangle.size(), 0));
        for(int i = triangle.size() - 1; i >= 0; i--){
            for(int j = triangle[i].size() - 1; j >= 0; j--){
                if(i == triangle.size() - 1) dp[i][j] = triangle[i][j];
                else{
                    dp[i][j] = min(triangle[i][j] + dp[i + 1][j], triangle[i][j] + dp[i + 1][j + 1]);
                }
            }
        }
        return dp[0][0];
    }
};


/*------------------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * n)
  Space Complexity: O(n)
--------------------------------------------------------------*/

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(n, 0);
        vector<int> prev(n, 0);
        for(int i = 0; i <= n - 1; i++){
            dp[i] = triangle[n - 1][i];
        }
        for(int i = n - 2; i >= 0; i--){
            prev = dp;
            for(int j = triangle[i].size() - 1; j >= 0; j--){
                dp[j] = min(triangle[i][j] + prev[j], triangle[i][j] + prev[j + 1]);
            }
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/triangle/description/
Author: M.R.Naganathan
*/
  
