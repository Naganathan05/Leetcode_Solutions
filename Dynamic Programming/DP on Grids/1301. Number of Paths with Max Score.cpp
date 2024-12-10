/*----------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-------------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    pair<int, int> maxPath(vector<string>& board, int i, int j, map<pair<int, int>, pair<int, int>>& dp) {
        if (i == 0 && j == 0) return {0, 1};
        if (i < 0 || j < 0 || board[i][j] == 'X') return {-1e9, 0};

        if (dp.find({i, j}) != dp.end()) return dp[{i, j}];

        int currVal = (board[i][j] != 'S') ? board[i][j] - '0' : 0; 
        auto topMove = maxPath(board, i - 1, j, dp);
        auto leftMove = maxPath(board, i, j - 1, dp);
        auto topLeftMove = maxPath(board, i - 1, j - 1, dp);

        int maxMove = max({topMove.first, leftMove.first, topLeftMove.first});
        int numPaths = 0;

        if (topMove.first == maxMove) numPaths = (numPaths + topMove.second) % mod;
        if (leftMove.first == maxMove) numPaths = (numPaths + leftMove.second) % mod;
        if (topLeftMove.first == maxMove) numPaths = (numPaths + topLeftMove.second) % mod;

        return dp[{i, j}] = {(maxMove + currVal) % mod, numPaths % mod};
    }

    vector<int> pathsWithMaxScore(vector<string>& board) {
        int n = board.size();
        int m = board[0].size();

        if (board[n - 1][m - 1] == 'X') return {0, 0};

        map<pair<int, int>, pair<int, int>> dp;
        auto ans = maxPath(board, n - 1, m - 1, dp);
        if (ans.first < 0) return {0, 0};
        return {ans.first, ans.second};
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-paths-with-max-score/
Author: M.R.Naganathan
*/
