/*-------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(n)
---------------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    long long decodeString(string &s, int i, vector<long long> &dp) {
        if (i == s.length()) return 1;
        if (dp[i] != -1) return dp[i];

        long long ways = 0;

        // One Digit
        if (s[i] == '*') ways = (ways + 9 * decodeString(s, i + 1, dp)) % mod;
        else if (s[i] != '0') ways = (ways + decodeString(s, i + 1, dp)) % mod;

        // Two Digit
        if (i + 1 < s.length()) {
            if (s[i] == '*' && s[i + 1] == '*') ways = (ways + 15 * decodeString(s, i + 2, dp)) % mod; // (11-19) && (21-26)
            else if (s[i] == '*') {
                if (s[i + 1] >= '0' && s[i + 1] <= '6') ways = (ways + 2 * decodeString(s, i + 2, dp)) % mod; // (10-16) && (20-26)
                else ways = (ways + decodeString(s, i + 2, dp)) % mod; // (17-19)
            } 
            else if (s[i + 1] == '*') {
                if (s[i] == '1')  ways = (ways + 9 * decodeString(s, i + 2, dp)) % mod; // (11-19)
                else if (s[i] == '2') ways = (ways + 6 * decodeString(s, i + 2, dp)) % mod; // (21-26)
            } 
            else {
                int val = (s[i] - '0') * 10 + (s[i + 1] - '0');
                if (val >= 10 && val <= 26) {
                    ways = (ways + decodeString(s, i + 2, dp)) % mod;
                }
            }
        }
        return dp[i] = ways;
    }

    int numDecodings(string s) {
        int n = s.length();
        vector<long long> dp(n, -1);
        return decodeString(s, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/decode-ways-ii/
Author: M.R.Naganathan
*/
