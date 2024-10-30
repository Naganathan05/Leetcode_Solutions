/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
------------------------------*/

class Solution {
public:
    bool checkIfCanBreak(string s1, string s2) {
        sort(s1.begin(), s1.end());
        sort(s2.begin(), s2.end());

        bool s1Breakss2 = true, s2Breakss1 = true;
        for(int i = 0; i <= s1.length() - 1; i++){
            if(s1[i] > s2[i]) s2Breakss1 = false;
            if(s1[i] < s2[i]) s1Breakss2 = false;
        }
        return s1Breakss2 || s2Breakss1;
    }
};

/*
https://leetcode.com/problems/check-if-a-string-can-break-another-string/
Author: M.R.Naganathan
*/
