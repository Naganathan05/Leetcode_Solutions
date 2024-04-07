/*---------------------------------------------
Method 1: Memoization
  Time Complexity: O(n * m)
  Space Complexity: O(n * m) + O(max(n, m))
------------------------------------------------*/

class Solution {
public:
    int Delete(string &s, string &t, int i, int j, vector<vector<int>> &dp){
        if(i < 0 && j < 0) return 0;
        if(i < 0 && j >= 0){
            int cost = 0;
            for(int k = 0; k <= j; k++) cost += (int)t[k];
            return cost;
        }
        if(j < 0 && i >= 0){
            int cost = 0;
            for(int k = 0; k <= i; k++) cost += (int)s[k];
            return cost;
        }

        if(dp[i][j] != -1) return dp[i][j];

        if(s[i] == t[j]) dp[i][j] = Delete(s, t, i - 1, j - 1, dp);
        else dp[i][j] = min((int)s[i] + Delete(s, t, i - 1, j, dp), (int)t[j] + Delete(s, t, i, j - 1, dp));
        return dp[i][j];
    }

    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length(), vector<int> (s2.length(), -1));
        return Delete(s1, s2, s1.length() - 1, s2.length() - 1, dp);
    }
};

/*------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
---------------------------------------------*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<vector<int>> dp(s1.length() + 1, vector<int> (s2.length() + 1, 0));

        dp[0][0] = 0;
        for(int j = 1; j <= s2.length(); j++){
            int cost = 0;
            for(int k = 1; k <= j; k++) cost += (int)s2[k - 1];
            dp[0][j] = cost;
        }
        for(int i = 1; i <= s1.length(); i++){
            int cost = 0;
            for(int k = 1; k <= i; k++) cost += (int)s1[k - 1];
            dp[i][0] = cost;
        }

        for(int i = 1; i <= s1.length(); i++){
            for(int j = 1; j <= s2.length(); j++){
                if(s1[i - 1] == s2[j - 1]) dp[i][j] = dp[i - 1][j - 1];
                else dp[i][j] = min((int)s1[i - 1] + dp[i - 1][j], (int)s2[j - 1] + dp[i][j - 1]);
            }
        }
        return dp[s1.length()][s2.length()];
    }
};

/*----------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(n * m)
  Space Complexity: O(m)
-------------------------------------------------*/

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        vector<int> prev(s2.length() + 1, 0), curr(s2.length() + 1, 0);

        for(int j = 1; j <= s2.length(); j++){
            int cost = 0;
            for(int k = 1; k <= j; k++) cost += (int)s2[k - 1];
            curr[j] = cost;
        }

        int cost = 0;
        for(int i = 1; i <= s1.length(); i++){
            prev = curr;
            cost += (int)s1[i - 1];
            curr[0] = cost;
            for(int j = 1; j <= s2.length(); j++){
                if(s1[i - 1] == s2[j - 1]) curr[j] = prev[j - 1];
                else curr[j] = min((int)s1[i - 1] + prev[j], (int)s2[j - 1] + curr[j - 1]);
            }
        }
        return curr[s2.length()];
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-ascii-delete-sum-for-two-strings/description/
Author: M.R.Naganathan
*/
