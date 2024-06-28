/*----------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(max(m, n))
------------------------------------*/

class Solution {
public:
    int increasingPath(vector<vector<int>> &matrix, int i, int j, int prev, vector<vector<int>> &dp){
        if(i < 0 || j < 0 || i == matrix.size() || j == matrix[0].size() || prev >= matrix[i][j]) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        int left = 1 + increasingPath(matrix, i, j - 1, matrix[i][j], dp);
        int right = 1 + increasingPath(matrix, i, j + 1, matrix[i][j], dp);
        int up = 1 + increasingPath(matrix, i - 1, j, matrix[i][j], dp);
        int down = 1 + increasingPath(matrix, i + 1, j, matrix[i][j], dp);
        return dp[i][j] = max({left, right, up, down});
    }

    int longestIncreasingPath(vector<vector<int>>& matrix) {
        vector<vector<int>> dp(matrix.size(), vector<int> (matrix[0].size(), -1));
        int maxLen = 0;
        for(int i = 0; i <= matrix.size() - 1; i++){
            for(int j = 0; j <= matrix[i].size() - 1; j++){
                maxLen = max(maxLen, increasingPath(matrix, i, j, -1, dp));
            }
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-increasing-path-in-a-matrix/
Author: M.R.Naganathan
*/
