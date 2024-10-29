/*---------------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n * m) + O(n)
------------------------------------*/

class Solution {
public:
    int Move(vector<vector<int>> &grid, int i, int j, vector<vector<int>> &dp) {
        int n = grid.size();
        int m = grid[0].size();
        
        if (dp[i][j] != -1) return dp[i][j];

        int maxMoves = 0;
        vector<pair<int, int>> directions = {{-1, 1}, {0, 1}, {1, 1}};
        for (auto &dir : directions) {
            int newX = i + dir.first;
            int newY = j + dir.second;
            if (newX >= 0 && newX < n && newY < m && grid[newX][newY] > grid[i][j]) {
                maxMoves = max(maxMoves, 1 + Move(grid, newX, newY, dp));
            }
        }
        return dp[i][j] = maxMoves;
    }

    int maxMoves(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dp(n, vector<int>(m, -1));
        int result = 0;

        for (int i = 0; i < n; i++) result = max(result, Move(grid, i, 0, dp));
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-moves-in-a-grid/
Author: M.R.Naganathan
*/
