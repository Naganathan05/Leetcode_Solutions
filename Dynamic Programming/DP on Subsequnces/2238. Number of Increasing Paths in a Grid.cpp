/*---------------------------------
Method - Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(max(m, n))
------------------------------------*/

class Solution {
    int mod = 1e9 + 7;
public:
    int count(vector<vector<int>> &grid, int i, int j, int prev, vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i == grid.size() || j == grid[0].size() || prev >= grid[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = count(grid, i, j - 1, grid[i][j], dp);
        int right = count(grid, i, j + 1, grid[i][j], dp);
        int up = count(grid, i - 1, j, grid[i][j], dp);
        int down = count(grid, i + 1, j, grid[i][j], dp);
        return dp[i][j] = 1 + (left + right + up + down) % mod;
    }

    int countPaths(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size(), -1));
        int totalCount = 0;
        for(int i = 0; i <= grid.size() - 1; i++){
            for(int j = 0; j <= grid[0].size() - 1; j++){
                totalCount = (totalCount + count(grid, i, j, -1, dp)) % mod;
            }
        }
        return totalCount;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-increasing-paths-in-a-grid/
Author: M.R.Naganathan
*/
