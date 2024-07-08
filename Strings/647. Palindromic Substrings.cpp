/*-----------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(1)
-------------------------------*/

class Solution {
public:
    int getNumPalindrome(string &s, int i, int j){
        if(j == s.length()) return 0;
        int numPalindrome = 0;
        while(i >= 0 && j < s.length() && s[i] == s[j]){
            numPalindrome += 1;
            i -= 1;
            j += 1;
        }
        return numPalindrome;
    }

    int countSubstrings(string s) {
        int totPalindromes = 0;
        for(int i = 0; i <= s.length() - 1; i++){
            totPalindromes += (getNumPalindrome(s, i , i) + getNumPalindrome(s, i, i + 1));
        }
        return totPalindromes;
    }
};

/*
Question Link: https://leetcode.com/problems/palindromic-substrings/
Author: M.R.Naganathan
*/
