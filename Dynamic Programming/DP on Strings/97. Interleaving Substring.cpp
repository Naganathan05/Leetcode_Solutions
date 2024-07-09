/*----------------------------------------
Method: Memoization
  Time Complexity: O(n * m * k)
  Space Complexity: O(n * m * k) + O(n)
------------------------------------------*/

class Solution {
public:
    bool InterLeave(string s1, string s2, string s3, int i, int j, int k, vector<vector<vector<int>>> &dp) {
        if (i < 0 && j < 0 && k < 0) return true;
        if (i < 0 && j < 0 || k < 0) return false;
        if (dp[i + 1][j + 1][k + 1] != -1) return dp[i + 1][j + 1][k + 1];
        
        bool maxPick = false;
        if (i >= 0 && s1[i] == s3[k]) maxPick |= InterLeave(s1, s2, s3, i - 1, j, k - 1, dp);
        if (j >= 0 && s2[j] == s3[k]) maxPick |= InterLeave(s1, s2, s3, i, j - 1, k - 1, dp);
        return dp[i + 1][j + 1][k + 1] = maxPick;
    }

    bool isInterleave(string s1, string s2, string s3) {
        vector<vector<vector<int>>> dp(s1.length() + 1, vector<vector<int>> (s2.length() + 1, vector<int> (s3.length() + 1, -1)));
        return InterLeave(s1, s2, s3, s1.length() - 1, s2.length() - 1, s3.length() - 1, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/interleaving-string/description/
Author: M.R.Naganathan
*/
