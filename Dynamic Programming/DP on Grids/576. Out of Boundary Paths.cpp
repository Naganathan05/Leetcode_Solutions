/*--------------------------------------------------------
Method: Memoization
  Time Complexity: O(m * n * maxMoves)
  Space Complexity: O(m * n * maxMoves) + O(n * maxMoves)
----------------------------------------------------------*/

class Solution {
public:
    int find(int i, int j, int n, int m, int maxMove, vector<vector<vector<long>>> &dp){
        if(i < 0 || j < 0 || i == m || j == n) return 1;
        if(!maxMove) return 0;

        if(dp[i][j][maxMove] != -1) return dp[i][j][maxMove];

        long move_up = 0, move_down = 0, move_left = 0, move_right = 0;
        move_up = find(i - 1, j, n, m, maxMove - 1, dp);
        move_down = find(i + 1, j, n, m, maxMove - 1, dp);
        move_left = find(i, j - 1, n, m, maxMove - 1, dp);
        move_right = find(i, j + 1, n, m, maxMove - 1, dp);
        return dp[i][j][maxMove] = (move_up + move_down + move_left + move_right) % (1000000007);
    }

    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        vector<vector<vector<long>>> dp(m, vector<vector<long>> (n, vector<long> (maxMove + 1, -1)));
        return find(startRow, startColumn, n, m, maxMove, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/out-of-boundary-paths/
Author: M.R.Naganathan
*/
