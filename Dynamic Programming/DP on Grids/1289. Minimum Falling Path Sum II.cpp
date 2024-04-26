/*-----------------------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + o(n)
--------------------------------------------*/

class Solution {
public:
    int falling(vector<vector<int>> &grid, int ind, int prev, vector<vector<int>>& dp){
        if(ind == 0){
            int minpoint = INT_MAX;
            for(int i = 0; i <= grid[0].size() - 1; i++){
                if(minpoint > grid[ind][i] && i != prev){
                    minpoint = grid[ind][i];
                }
                dp[ind][i] = grid[ind][i];
            }
            return minpoint;
        }

        if(dp[ind][prev] != -1) return dp[ind][prev];

        int min_point = INT_MAX;
        for(int i = 0; i <= grid[ind].size() - 1; i++){
            if(i != prev){
                int point = grid[ind][i] + falling(grid, ind - 1, i, dp);
                min_point = min(min_point, point);
            }
        }
        return dp[ind][prev] = min_point;
    }

    int minFallingPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(), vector<int> (grid[0].size() + 1, -1));
        return falling(grid, grid.size() - 1, grid[0].size(), dp);
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-falling-path-sum-ii/description/
Author: M.R.Naganathan
*/
