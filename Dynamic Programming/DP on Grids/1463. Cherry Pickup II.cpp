/*-------------------------------------------
Method: Memoization
  Time Complexity: O(m * n * n)
  Space Complexity: O(m * n * n) + O(n * n)
----------------------------------------------*/

class Solution {
public:
    int Cherry(vector<vector<int>> &grid, int i, int j1, int j2, vector<vector<vector<int>>> &dp){
        if(j1 < 0 || j2 < 0 || j1 >= grid[i].size() || j2 >= grid[i].size()) return -1e8;
        if(i == grid.size() - 1){
            if(j1 == j2) return grid[i][j1];
            return grid[i][j1] + grid[i][j2];
        }

        if(dp[i][j1][j2] != -1) return dp[i][j1][j2];

        int maxChoco = 0;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int currChoco = 0;
                if(j1 == j2) currChoco = grid[i][j1] + Cherry(grid, i + 1, j1 + dj1, j2 + dj2, dp);
                else currChoco = grid[i][j1] + grid[i][j2] + Cherry(grid, i + 1, j1 + dj1, j2 + dj2, dp);
                maxChoco = max(maxChoco, currChoco);
            }
        }
        return dp[i][j1][j2] = maxChoco;
    }

    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(), vector<vector<int>> (grid[0].size(), vector<int> (grid[0].size(), -1)));
        return Cherry(grid, 0, 0, grid[0].size() - 1, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/cherry-pickup-ii/
Author: M.R.Naganathan
*/
