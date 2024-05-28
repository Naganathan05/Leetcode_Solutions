/*--------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------------*/

class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int currCost = 0, max_len = 0, i = 0, j = 0;
        while(j < s.length()) {
            currCost += abs(s[j] - t[j]);
            while(currCost > maxCost) {
                currCost -= abs(s[i] - t[i]);
                i += 1;
            }
            max_len = max(max_len, j - i + 1);
            j += 1;
        }
        return max_len;
    }
};

/*
Question Link: https://leetcode.com/problems/get-equal-substrings-within-budget/
Author: M.R.Naganathan
*/
