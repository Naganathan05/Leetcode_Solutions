/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(m + n)
-------------------------------------------------*/

class Solution {
public:
    bool recursion(string s, string p, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return true;
        if(i < 0 && j >= 0){
            for(int k = 0; k <= j; k++){
                if(p[k] != '*') return false;
            }
            return true;
        }
        if(i < 0 || j < 0) return false;

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == p[j]){
            dp[i][j] = recursion(s, p, i - 1, j - 1, dp);
        }
        else if(p[j] == '*'){
            bool l = false;
            l = recursion(s, p, i - 1, j - 1, dp) || recursion(s, p , i - 1, j, dp);
            dp[i][j] = l || recursion(s, p, i, j - 1, dp);
        }
        else if(p[j] == '?'){
            dp[i][j] = recursion(s, p, i - 1, j - 1, dp);
        }
        else{
            return false;
        }
        return dp[i][j];
    }

    bool isMatch(string s, string p) {
        vector<vector<int>> dp(s.length(), vector<int>(p.length(), -1));
        return recursion(s, p, s.length() - 1, p.length() - 1, dp);
    }
};

/*----------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------------------------------*/

class Solution {
public:
    bool isMatch(string s, string p) {
        vector<vector<bool>> dp(s.length() + 1, vector<bool>(p.length() + 1, false));
        dp[0][0] = true;
        for(int j = 1; j <= s.length(); j++){
            dp[j][0] = false;
        }
        for(int i = 1; i <= p.length(); i++){
            bool flag = true;
            for(int j = 1; j <= i; j++){
                if(p[j - 1] != '*'){
                    flag = false;
                    break;
                }
            }
            dp[0][i] = flag;
        }

        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= p.length(); j++){
                if(s[i - 1] == p[j - 1]){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else if(p[j - 1] == '*'){
                    dp[i][j] = dp[i - 1][j - 1] || dp[i - 1][j] || dp[i][j - 1];
                }
                else if(p[j - 1] == '?'){
                    dp[i][j] = dp[i - 1][j - 1];
                }
                else{
                    dp[i][j] = false;
                }
            }
        }
        return dp[s.length()][p.length()];
    }
};

/*
Question Link: https://leetcode.com/problems/wildcard-matching/description/
Author: M.R.Naganathan
*/
