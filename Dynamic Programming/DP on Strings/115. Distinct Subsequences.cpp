/*-----------------------------------------------
Method 1: Memoization
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(m + n)
--------------------------------------------------*/

class Solution {
public:
    int recursion(string s, string t, int i, int j, vector<vector<int>> &dp){
        if(j < 0) return 1;
        if(i < 0) return 0;

        if(dp[i][j] != -1) return dp[i][j];

        int Pick = 0, noPick = 0;
        if(s[i] == t[j]) Pick = recursion(s, t, i - 1, j - 1, dp) + recursion(s, t, i - 1, j, dp);
        else{
            noPick = recursion(s, t, i - 1, j, dp);
        }
        return dp[i][j] = Pick + noPick;
    }
    
    int numDistinct(string s, string t) {
        vector<vector<int>> dp (s.length(), vector<int> (t.length(), -1));
        return recursion(s, t, s.length() - 1, t.length() - 1, dp);
    }
};

/*----------------------------------------------------
Method 2: Tabulation
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------------------------------*/

class Solution {
public:  
    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        vector<vector<long long>> dp (s.length() + 1, vector<long long> (t.length() + 1, 0));
        for(int i = 0; i <= s.length(); i++){
            dp[i][0] = 1;
        }
        for(int i = 1; i <= t.length(); i++){
            dp[0][i] = 0;
        }

        for(int i = 1; i <= s.length(); i++){
            for(int j = 1; j <= t.length(); j++){
                if(s[i - 1] == t[j - 1]) dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % mod;
                else dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[s.length()][t.length()];
    }
};

/*-------------------------------------------------------
Method 3: Space Optimization
  Time Complexity: O(m * n)
  Space Complexity: O(n)
----------------------------------------------------------*/

class Solution {
public:
    int numDistinct(string s, string t) {
        int mod = 1e9 + 7;
        vector<long long> curr(t.length() + 1, 0), prev(t.length() + 1, 0);
        curr[0] = 1;

        for(int i = 1; i <= s.length(); i++){
            prev = curr;
            for(int j = 1; j <= t.length(); j++){
                if(s[i - 1] == t[j - 1]) curr[j] = (prev[j - 1] + prev[j]) % mod;
                else curr[j] = prev[j];
            }
        }
        return curr[t.length()];
    }
};

/*
Question Link: https://leetcode.com/problems/distinct-subsequences/
Author: M.R.Naganathan
*/
