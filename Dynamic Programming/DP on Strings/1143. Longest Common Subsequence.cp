/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(m + n)
-------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(string text1, string text2, int i, int j, vector<vector<int>> &dp){
        if (i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + recursiveFunction(text1, text2, i - 1, j - 1, dp);

        return dp[i][j] = max(recursiveFunction(text1, text2, i - 1, j, dp), recursiveFunction(text1, text2, i, j - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        return recursiveFunction(text1, text2, text1.length() - 1, text2.length() - 1, dp);
    }
};

/*---------------------------------------------------------
Method 2: Tabulation 
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(string text1, string text2, int i, int j, vector<vector<int>> &dp){
        if (i < 0 || j < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) return dp[i][j] = 1 + recursiveFunction(text1, text2, i - 1, j - 1, dp);

        return dp[i][j] = max(recursiveFunction(text1, text2, i - 1, j, dp), recursiveFunction(text1, text2, i, j - 1, dp));
    }

    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>> dp(text1.length(), vector<int> (text2.length(), -1));
        for(int i = 0; i <= text1.length() - 1; i++){
            for(int j = 0; j <= text2.length() - 1; j++){
                if(text1[i] == text2[j]){
                    if(i - 1 >= 0 && j - 1 >= 0) dp[i][j] = 1 + dp[i - 1][j - 1];
                    else{
                        dp[i][j] = 1;
                    }
                }
                else{
                    int left = 0, right = 0;
                    if(i - 1 >= 0) left = dp[i - 1][j];
                    if(j - 1 >= 0) right = dp[i][j - 1];
                    dp[i][j] = max(left, right);
                }
            }
        }
        return dp[text1.length() - 1][text2.length() - 1];
    }
};

/*-----------------------------------------------------------
Method 3: Tabulation => Shifted Index Approach
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
--------------------------------------------------------------*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<vector<int>> dp(m + 1, vector<int> (n + 1, -1));
        for(int i = 0; i <= m; i++) dp[i][0] = 0;
        for(int i = 0; i <= n; i++) dp[0][i] = 0;

        for(int i = 1; i <= m; i++){
            for(int j = 1; j <= n; j++){
                if(text1[i - 1] == text2[j - 1]) dp[i][j] = 1 + dp[i - 1][j - 1];
                else dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return dp[m][n];
    }
};

/*----------------------------------------------------------------
Method 4: Space Optimization
  Time Complexity: O(m * n)
  Space Complexity: O(n)
-------------------------------------------------------------------*/

class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int m = text1.length();
        int n = text2.length();
        vector<int> prev(n + 1, 0), curr(n + 1, 0);
        for(int i = 0; i <= n; i++) curr[i] = 0;

        for(int i = 1; i <= m; i++){
            prev = curr;
            for(int j = 1; j <= n; j++){
                if(text1[i - 1] == text2[j - 1]) curr[j] = 1 + prev[j - 1];
                else curr[j] = max(prev[j], curr[j - 1]);
            }
        }
        return curr[n];
    }
};

/*
Question Link: https://leetcode.com/problems/longest-common-subsequence/description/
Author: M.R.Naganathan
*/
