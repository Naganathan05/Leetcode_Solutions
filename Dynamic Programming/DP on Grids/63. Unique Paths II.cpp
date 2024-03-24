/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(vector<vector<int>> &obstacleGrid, int i, int j, vector<vector<int>> &dp){
        if(i == 0 && j == 0) return 1;

        if(dp[i][j] != -1) return dp[i][j];

        int up = 0, left = 0;
        if(i - 1 >= 0 && obstacleGrid[i - 1][j] != 1) up = recursiveFunction(obstacleGrid, i - 1, j, dp);
        if(j - 1 >= 0 && obstacleGrid[i][j - 1] != 1) left = recursiveFunction(obstacleGrid, i, j - 1, dp);

        return dp[i][j] = up + left;
    }

    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, -1));
        int m = obstacleGrid.size() - 1;
        int n = obstacleGrid[0].size() - 1; 
        if(obstacleGrid[m][n] || obstacleGrid[0][0]) return 0;
        return recursiveFunction(obstacleGrid, m, n, dp);
    }
};

/*---------------------------------------------------------
Method 2: Tabulation => Note: Recursive Stack Space Avoided
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------------------------------------*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() - 1;
        int n = obstacleGrid[0].size() - 1; 
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        if(obstacleGrid[m][n] || obstacleGrid[0][0]) return 0;

        for(int i = 0; i <= m; i++){
            for(int j = 0; j <= n; j++){
                if(!i && !j) dp[i][j] = 1;
                else{
                    if(i - 1 >= 0 && !obstacleGrid[i - 1][j]) dp[i][j] += dp[i - 1][j];
                    if(j - 1 >= 0 && !obstacleGrid[i][j - 1]) dp[i][j] += dp[i][j - 1];
                }
            }
        }
        return dp[m][n];
    }
};

/*-----------------------------------------
Method 3: Space Optimization
  Time Complexity: O(m * n)
  Space Complexity: O(n)
-------------------------------------------*/

class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size() - 1;
        int n = obstacleGrid[0].size() - 1; 
        vector<int> prev(n + 1, 0);
        if(obstacleGrid[m][n] || obstacleGrid[0][0]) return 0;

        for(int i = 0; i <= m; i++){
            vector<int> curr(n + 1, 0);
            for(int j = 0; j <= n; j++){
                if(!i && !j) curr[j] = 1;
                else{
                    if(i - 1 >= 0 && !obstacleGrid[i - 1][j]) curr[j] += prev[j];
                    if(j - 1 >= 0 && !obstacleGrid[i][j - 1]) curr[j] += curr[j - 1];
                }
            }
            prev = curr;
        }
        return prev[n];
    }
};

/*
Question Link: https://leetcode.com/problems/unique-paths-ii/description/
Author: M.R.Naganathan
*/
