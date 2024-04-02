/*----------------------------------------
Method 1: Two Pointer Memoization
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------------*/

class Solution {
public:
    int palindrome(string str, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(checkPalindrome(str, i, j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int min_cuts = 1e9;
        for(int k = i; k < j; k++){
            int cuts = 1 + palindrome(str, i, k, dp) + palindrome(str, k + 1, j, dp);
            min_cuts = min(cuts, min_cuts);
        }
        return dp[i][j] = min_cuts;
    }

    int minCut(string s) {
        vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
        return palindrome(s, 0, s.length() - 1, dp);
    }

    bool checkPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};

/*-----------------------------------------
Method 2: Two Pointer Tabulation
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n)
-------------------------------------------*/

class Solution {
public:
    int palindrome(string str, int i, int j, vector<vector<int>> &dp){
        if(i > j) return 0;
        
        if(checkPalindrome(str, i, j)) return 0;
        if(dp[i][j] != -1) return dp[i][j];
        
        int min_cuts = 1e9;
        for(int k = i; k < j; k++){
            int cuts = 1 + palindrome(str, i, k, dp) + palindrome(str, k + 1, j, dp);
            min_cuts = min(cuts, min_cuts);
        }
        return dp[i][j] = min_cuts;
    }

    int minCut(string s) {
        vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
        
        for(int i = s.length() - 1; i >= 0; i--){
            for(int j = i; j <= s.length() - 1; j++){
                if(checkPalindrome(s, i, j)) dp[i][j] = 0;
                else{
                    int min_cuts = 1e9;
                    for(int k = i; k < j; k++){
                        int cuts = 1 + dp[i][k] + dp[k + 1][j];
                        min_cuts = min(cuts, min_cuts);
                    }
                    dp[i][j] = min_cuts;
                }
            }
        }
        return dp[0][s.length() - 1];
    }

    bool checkPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};

/*-----------------------------------------------
Method 3: One Pointer Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n) + O(n)
-------------------------------------------------*/

class Solution {
public:
    int solveMem(string str, int i, int n,vector<int> &dp) {
        if(i == n) return 0;
    
        if(dp[i] != -1) return dp[i];

        int mini = INT_MAX;
        for(int j = i; j < n; j++){
            if(checkPalindrome(str, i, j)){
                int ans = 1 + solveMem(str, j+1, n, dp);
                mini = min(ans, mini);
            }
        }
        return dp[i] = mini;
    }

    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n + 1, -1);
        return solveMem(s, 0, n, dp) - 1;
    }

    bool checkPalindrome(string str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};

/*------------------------------------------------
Method 4: One Pointer Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n)
--------------------------------------------------*/

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<int> dp(n + 1, 0);

        for(int i = n - 1; i >= 0; i--){
            int mini = INT_MAX;
            for(int j = i; j < n; j++){
                if(checkPalindrome(s, i, j)){
                    int ans = 1 + dp[j + 1];
                    mini = min(mini, ans);
                }
            }
            dp[i] = mini;
        }
        return dp[0] - 1;
    }

    bool checkPalindrome(string &str, int i, int j){
        while(i < j){
            if(str[i] != str[j]) return false;
            i += 1;
            j -= 1;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/palindrome-partitioning-ii/description/
Author: M.R.Naganathan
*/
