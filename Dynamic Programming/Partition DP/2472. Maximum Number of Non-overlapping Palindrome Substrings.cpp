/*-----------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
--------------------------------*/

class Solution {
public:
    int Partition(string &s, int i, int k, vector<vector<bool>> &isPalindrome, vector<int> &dp){
        if(i == s.length()) return 0;
        if(dp[i] != -1) return dp[i];

        int maxPalindrome = Partition(s, i + 1, k, isPalindrome, dp);
        for(int j = i + k - 1; j <= s.length() - 1; j++){
            if(j >= s.length()) break;
            if(isPalindrome[i][j]) maxPalindrome = max(maxPalindrome, 1 + Partition(s, j + 1, k, isPalindrome, dp));
        }
        return dp[i] = maxPalindrome;
    }

    int maxPalindromes(string s, int k) {
        vector<vector<bool>> isPalindrome(s.length(), vector<bool> (s.length(), false));
        for(int i = s.length() - 1; i >= 0; i--){
            for(int j = i; j <= s.length() - 1; j++){
                if(s[i] == s[j] && (j - i + 1 <= 2 || isPalindrome[i + 1][j - 1])){
                    isPalindrome[i][j] = true;
                }
            }
        }

        vector<int> dp(s.length(), -1);
        return Partition(s, 0, k, isPalindrome, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-non-overlapping-palindrome-substrings/
Author: M.R.Naganathan
*/
