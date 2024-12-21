/*----------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
------------------------------*/

class Solution {
public:
    const int MOD = 1e9 + 7;
    int dfs(int i, int j, int xor_val, vector<vector<int>>& grid, int k, vector<vector<unordered_map<int, int>>>& dp) {
        int m = grid.size(), n = grid[0].size();
        if (i >= m || j >= n) return 0;
        
        xor_val ^= grid[i][j];
        
        if (i == m - 1 && j == n - 1) return xor_val == k ? 1 : 0;
        
        if (dp[i][j].count(xor_val)) return dp[i][j][xor_val];

        int right = dfs(i, j + 1, xor_val, grid, k, dp);
        int down = dfs(i + 1, j, xor_val, grid, k, dp);

        return dp[i][j][xor_val] = (right + down) % MOD;
    }

    int countPathsWithXorValue(vector<vector<int>>& grid, int k) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<unordered_map<int, int>>> dp(m, vector<unordered_map<int, int>>(n));
        return dfs(0, 0, 0, grid, k, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/count-paths-with-the-given-xor-value/
Author: M.R.Naganathan
*/
