/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    bool canConstruct(string s, int k) {
        if(s.length() < k) return false;
        unordered_map<char, int> freq;
        for(char c : s) freq[c] += 1;
        int numOdds = 0;
        for(auto i : freq) numOdds += (i.second % 2);
        return numOdds <= k;
    }
};

/*
Question Link: https://leetcode.com/problems/construct-k-palindrome-strings/
Author: M.R.Naganathan
*/
