/*----------------------------------------
Method 1: Memoization
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n) + O(n)
------------------------------------------*/

class Solution {
public:
    bool word(string s, int i, int j, unordered_map<string, int> &dict, vector<vector<int>> &dp){
        if(i > j) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(dict[s.substr(i, j - i + 1)] > 0) return true;

        bool final_result = false;
        for(int k = i; k < j; k++){
            bool result;
            result = (word(s, i, k, dict, dp)) && (word(s, k + 1, j, dict, dp));
            final_result = final_result || result;
        }
        return dp[i][j] = final_result;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_map<string , int> dict;
       for(string str : wordDict) dict[str] += 1;
       vector<vector<int>> dp(s.length(), vector<int> (s.length(), -1));
       return word(s, 0, s.length() - 1, dict, dp);
    }
};

/*------------------------------------------
Method 2: Tabulation
  Time Complexity: O(n * n * n)
  Space Complexity: O(n * n)
--------------------------------------------*/

class Solution {
public:
    bool word(string s, int i, int j, unordered_map<string, int> &dict, vector<vector<int>> &dp){
        if(i > j) return true;
        if(dp[i][j] != -1) return dp[i][j];

        if(dict[s.substr(i, j - i + 1)] > 0) return true;

        bool final_result = false;
        for(int k = i; k < j; k++){
            bool result;
            result = (word(s, i, k, dict, dp)) && (word(s, k + 1, j, dict, dp));
            final_result = final_result || result;
        }
        return dp[i][j] = final_result;
    }

    bool wordBreak(string s, vector<string>& wordDict) {
       unordered_map<string , int> dict;
       for(string str : wordDict) dict[str] += 1;
       vector<vector<int>> dp(s.length(), vector<int> (s.length(), 0));

       for(int i = s.length() - 1; i >= 0; i--){
        for(int j = i; j <= s.length() - 1; j++){
            if(dict[s.substr(i, j - i + 1)] > 0) dp[i][j] = true;
            else{
                bool final_results = false;
                for(int k = i; k < j; k++){
                    bool result;
                    result = dp[i][k] && dp[k + 1][j];
                    final_results = final_results || result;
                }
                dp[i][j] = final_results;
            }
        }
       }
       return dp[0][s.length() - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/word-break/description/
Author: M.R.Naganathan
*/
