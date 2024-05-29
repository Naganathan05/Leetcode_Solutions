/*---------------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
-----------------------------------------*/

class Solution {
public:
    int Decoding(string& s, int i, vector<int> &dp){
        if(i == s.length()) return 1;
        if(s[i] == '0') return 0;
        if(dp[i] != -1) return dp[i];

        int oneDigit = 0, twoDigit = 0;
        oneDigit = Decoding(s, i + 1, dp);
        int currAscii = 50;
        if(i + 1 < s.length()) currAscii = stoi(s.substr(i, 2));
        if(i + 1 < s.length() && currAscii <= 26) twoDigit = Decoding(s, i + 2, dp);
        return dp[i] = oneDigit + twoDigit;
    }

    int numDecodings(string s) {
        vector<int> dp(s.length(), -1);
        return Decoding(s, 0, dp);
    }
};

/*--------------------------------------------
Method: Tabulation
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    int numDecodings(string s) {
        vector<int> dp(s.length() + 1, 0);
        dp[s.length()] = 1;

        for(int i = s.length() - 1; i >= 0; i--){
            if(s[i] != '0'){
                int oneDigit = 0, twoDigit = 0;
                oneDigit = dp[i + 1];
                int currAscii = 50;
                if(i + 1 < s.length()) currAscii = stoi(s.substr(i, 2));
                if(i + 1 < s.length() && currAscii <= 26) twoDigit = dp[i + 2];
                dp[i] = oneDigit + twoDigit;
            }
        }
        return dp[0];
    }
};

/*
Question Link: https://leetcode.com/problems/decode-ways/description/
Author: M.R.Naganathan
*/
