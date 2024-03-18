/*-----------------------------------------------
Method: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(m + n)
--------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(string word1, string word2, int i, int j, vector<vector<int>> &dp){
        if(i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(word1[i] == word2[j]) return dp[i][j] = 1 + recursiveFunction(word1, word2, i - 1, j - 1, dp);

        return dp[i][j] = max(recursiveFunction(word1, word2, i - 1, j, dp), recursiveFunction(word1, word2, i, j - 1, dp));
    }
    
    int minDistance(string word1, string word2) {
        vector<vector<int>> dp(word1.length(), vector<int> (word2.length(), -1));
        int lcs = recursiveFunction(word1, word2, word1.length() - 1, word2.length() - 1, dp);
        int m = max(word1.length(), word2.length());
        int n = min(word1.length(), word2.length());
        return (m - lcs) + (n - lcs);
    }
};

/*
Question Link: https://leetcode.com/problems/delete-operation-for-two-strings/
Author: M.R.Naganathan
*/
