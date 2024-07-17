/*------------------------------------------
Method: Memoization
  Time Complexity: O(n * n * k)
  Space Complexity: O(n * n * k) + O(n * k)
---------------------------------------------*/

class Solution {
public:
    double knight(int n, int k, int i, int j, vector<vector<vector<double>>> &dp){
        if(i < 0 || j < 0 || i >= n || j >= n) return 0.0;
        if(k == 0) return 1.0;

        if(dp[i][j][k] != -1) return dp[i][j][k];

        vector<pair<int, int>> directions = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        double Probability = 0.0;
        for(auto dir : directions){
            Probability += ((0.125) * knight(n, k - 1, i + dir.first, j + dir.second, dp));
        }
        return dp[i][j][k] = Probability;
    }

    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>> (n, vector<double> (k + 1, -1)));
        return knight(n, k, row, column, dp);
    }
};

/*-----------------------------------------
Method: Tabulation
  Time Complexity:O(n * n * k)
  Space Complexity: O(n * n * k)
--------------------------------------------*/

class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<vector<double>>> dp(n, vector<vector<double>>(n, vector<double>(k + 1, 0.0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                dp[i][j][0] = 1.0;
            }
        }

        vector<pair<int, int>> directions = {{-2, 1}, {-1, 2}, {1, 2}, {2, 1}, {2, -1}, {1, -2}, {-1, -2}, {-2, -1}};
        for (int m = 1; m <= k; m++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    double Probability = 0.0;
                    for (auto dir : directions) {
                        int newX = i + dir.first;
                        int newY = j + dir.second;
                        if (newX >= 0 && newY >= 0 && newX < n && newY < n) Probability += (0.125 * dp[newX][newY][m - 1]);
                    }
                    dp[i][j][m] = Probability;
                }
            }
        }
        return dp[row][column][k];
    }
};

/*
Question Link: https://leetcode.com/problems/knight-probability-in-chessboard/description/
Author: M.R.Naganathan
*/
