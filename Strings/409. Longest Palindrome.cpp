/*-------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------*/

class Solution {
public:
    int longestPalindrome(string s) {
        int max_len = 0, flag = 0;
        unordered_map<char, int> freq;
        for(char c : s) freq[c] += 1;

        for(auto i : freq){
            if(i.second % 2 == 0) max_len += (i.second);
            else{
                max_len += (i.second - 1);
                flag = 1;
            }
        }
        return max_len + flag;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-palindrome/
Author: M.R.Naganathan
*/
