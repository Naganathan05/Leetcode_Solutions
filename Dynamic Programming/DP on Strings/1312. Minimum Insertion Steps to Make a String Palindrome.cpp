/*-----------------------------------------------
Method 1: Memoization => Note: MLE :(
  Time Complexity: O(n * n)
  Space Complexity: O(n * n) + O(n)
-------------------------------------------------*/

class Solution {
public:
    int recursiveFunction(string text1, string text2, int i, int j, vector<vector<int>> &dp){
        if (i < 0 || j < 0) return 0;
        if(dp[i][j] != -1) return dp[i][j];

        if(text1[i] == text2[j]) dp[i][j] = 1 +  recursiveFunction(text1, text2, i - 1, j - 1, dp);
        else dp[i][j] = max(recursiveFunction(text1, text2, i - 1, j, dp), recursiveFunction(text1, text2, i, j - 1, dp));
        return dp[i][j];
    }
    int minInsertions(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int> (n, -1));
        string text1 = s;
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n - i - 1]);
        }
        string text2 = s;
        return n - recursiveFunction(text1, text2, n - 1, n - 1, dp);
    }
};

/*---------------------------------------------------------
Method 2: Space Optimization
  Time Complexity: O(n * n)
  Space Complexity: O(n)
------------------------------------------------------------*/

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        vector<int> prev(n, 0), curr(n, 0);
        string text1 = s;
        for(int i = 0; i < n/2; i++){
            swap(s[i], s[n - i - 1]);
        }
        string text2 = s;
        for(int i = 0; i <= n - 1; i++){
            prev = curr;
            for(int j = 0; j <= n - 1; j++){
                if(text1[i] == text2[j]){
                    if(i - 1 >= 0 && j - 1 >= 0) curr[j] = 1 + prev[j - 1];
                    else curr[j] = 1;
                }
                else{
                    int left = 0, right = 0;
                    if(i - 1 >= 0) left = prev[j];
                    if(j - 1 >= 0) right = curr[j - 1];
                    curr[j] = max(left, right);
                }
            }
        }
        return n - curr[n - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-insertion-steps-to-make-a-string-palindrome/description/
Author: M.R.Naganathan
*/
