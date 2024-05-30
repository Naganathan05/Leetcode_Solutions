/*-----------------------------------------
Method: Memoization  
  Time Complexity: O(n * n)
  Space Complexity: O(n) + O(n)
-------------------------------------------*/

class Solution {
public:
    int dp[7001][2];
    int Jump(unordered_map<int, int> &forbidden, int i, int prevJump, int a, int b, int x) {
        if (i == x) return 0;
        if (i < 0 || i > 6000 || forbidden.find(i) != forbidden.end()) return 1e6;
        if (dp[i][prevJump] != -1) return dp[i][prevJump];

        dp[i][prevJump] = 1 + Jump(forbidden, i + a, 0, a, b, x);
        if (prevJump != 1) dp[i][prevJump] = min(dp[i][prevJump], 1 + Jump(forbidden, i - b, 1, a, b, x));

        return dp[i][prevJump];
    }

    int minimumJumps(vector<int>& forbidden, int a, int b, int x) {
        unordered_map<int, int> freq;
        for (int pos : forbidden) freq[pos] = 1;
        memset(dp,-1,sizeof(dp));
        int min_jump = Jump(freq, 0, 0, a, b, x);
        return min_jump >= 1e6 ? -1 : min_jump;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-jumps-to-reach-home/
Author: M.R.Naganathan
*/
