/*-----------------------
Method: Memoziation  
  Time Complexity: O(n)
  Space Comlexity: O(n)
--------------------------*/

class Solution {
public:
    long long Multiply(vector<int> &a, vector<int> &b, int i, int j, int k, vector<vector<vector<long long>>> &dp) {
        if(i == a.size() || k == 0) return 0;
        if(j == b.size()) return -1e18;

        if(dp[i][j][k] != -1) return dp[i][j][k];
        
        long long Pick = -1e18, noPick = -1e18;
        Pick = (1LL * a[i] * b[j]) + Multiply(a, b, i + 1, j + 1, k - 1, dp);
        noPick = Multiply(a, b, i, j + 1, k, dp);
        return dp[i][j][k] = max(Pick, noPick);
    }

    long long maxScore(vector<int>& a, vector<int>& b) {
        vector<vector<vector<long long>>> dp(a.size(), vector<vector<long long>>(b.size(), vector<long long>(5, -1)));
        return Multiply(a, b, 0, 0, 4, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-multiplication-score/
Author: M.R.Naganathan
*/
