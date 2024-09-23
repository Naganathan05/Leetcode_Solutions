/*---------------------------
Method: Memoization
  Time Complexity: O(n * n)
  Space Complexity: O(n + m)
------------------------------*/

class Solution {
public:
    int ExtraChar(string &s, int i, unordered_map<string, bool> &dict, vector<int> &dp){
        if(i == s.length()) return 0;
        if(dp[i] != -1) return dp[i];

        int minExtraChar = 1e9;
        for(int j = i; j <= s.length() - 1; j++){
            int Pick = 1e9, noPick = 1e9;
            if(dict.find(s.substr(i, j - i + 1)) != dict.end()) Pick = ExtraChar(s, j + 1, dict, dp);
            noPick = (j - i + 1) + ExtraChar(s, j + 1, dict, dp);
            minExtraChar = min({minExtraChar, Pick, noPick});
        }
        return dp[i] = minExtraChar;
    }

    int minExtraChar(string s, vector<string>& dictionary) {
        unordered_map<string, bool> dict;
        for(string& str : dictionary) dict[str] = true;
        vector<int> dp(s.length(), -1);
        return ExtraChar(s, 0, dict, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/extra-characters-in-a-string/
Author: M.R.Naganathan
*/
