/*------------------------------------
Method: Expand Around Center
  Time Complexity: O(n * n)
  Space Complexity: O(1)
---------------------------------------*/

class Solution {
public:
    string checkPalindrome(string &s, int left, int right){
        while(left >= 0 && right <= s.length() - 1 && s[left] == s[right]){
            left -= 1;
            right += 1;
        }
        return s.substr(left + 1, right - left - 1);
    }

    string longestPalindrome(string s) {
        if(s.length() <= 1) return s;
        string maxString = "";
        for(int i = 0; i <= s.length() - 2; i++){
            string oddPalindrome = checkPalindrome(s, i, i);
            string evenPalindrome = checkPalindrome(s, i, i + 1);
            if(maxString.length() <= oddPalindrome.length()) maxString = oddPalindrome;
            if(maxString.length() <= evenPalindrome.length()) maxString = evenPalindrome;
        }
        return maxString;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-palindromic-substring/
Author: M.R.Naganathan
*/
