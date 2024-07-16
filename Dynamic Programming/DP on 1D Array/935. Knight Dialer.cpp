/*---------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
-----------------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    int Dial(int n, int currNum, unordered_map<int, vector<int>> &moves, vector<vector<int>> &dp) {
        if (n == 0) return 1;
        if (dp[currNum][n] != -1) return dp[currNum][n];
        
        int totalMoves = 0;
        for (int nextNum : moves[currNum]) {
            totalMoves = (totalMoves + Dial(n - 1, nextNum, moves, dp)) % mod;
        }
        return dp[currNum][n] = totalMoves;
    }

    int knightDialer(int n) {
        if (n == 1) return 10;
        
        unordered_map<int, vector<int>> moves;
        moves[0] = {4, 6};
        moves[1] = {6, 8};
        moves[2] = {7, 9};
        moves[3] = {4, 8};
        moves[4] = {0, 3, 9};
        moves[5] = {}; 
        moves[6] = {0, 1, 7};
        moves[7] = {2, 6};
        moves[8] = {1, 3};
        moves[9] = {2, 4};

        vector<vector<int>> dp(10, vector<int>(n + 1, -1));
        int totalNums = 0;
        for (int i = 0; i < 10; i++) {
            totalNums = (totalNums + Dial(n - 1, i, moves, dp)) % mod;
        }
        return totalNums;
    }
};

/*
Question Link: https://leetcode.com/problems/knight-dialer/
Author: M.R.Naganathan
*/
