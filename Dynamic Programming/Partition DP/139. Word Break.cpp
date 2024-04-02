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

/*-----------------------------------------------
Method 3: One Pointer Tabulation
  Time Complexity: O(n * n)
  Space Complexity: O(n)
--------------------------------------------------*/

class Solution {
 public:
  bool wordBreak(string s, vector<string>& wordDict) {
    const int n = s.length();
    const int maxLength = getMaxLength(wordDict);
    const unordered_set<string> wordSet{begin(wordDict), end(wordDict)};
    vector<int> dp(n + 1);
    dp[0] = true;

    for (int i = 1; i <= n; ++i)
      for (int j = i - 1; j >= 0; --j) {
        if (i - j > maxLength)
          break;
        if (dp[j] && wordSet.count(s.substr(j, i - j))) {
          dp[i] = true;
          break;
        }
      }

    return dp[n];
  }

 private:
  int getMaxLength(const vector<string>& wordDict) {
    return max_element(begin(wordDict), end(wordDict),
                       [](const auto& a, const auto& b) {
                         return a.length() < b.length();
                       })
        ->length();
  }
};

/*
Question Link: https://leetcode.com/problems/word-break/description/
Author: M.R.Naganathan
*/
