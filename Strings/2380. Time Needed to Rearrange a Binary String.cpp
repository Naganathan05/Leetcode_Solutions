/*--------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int secondsToRemoveOccurrences(string s) {
        int seconds = 0, flag = true;
        while(flag) {
            flag = false;
            for (int i = 0; i < s.size() - 1; i++) {
                if (s[i] == '0' && s[i + 1] == '1') {
                    swap(s[i], s[i + 1]);
                    i += 1;
                    flag = true;
                }
            }
            seconds += flag;
        }
        return seconds;
    }
};

/*
Question Link: https://leetcode.com/problems/time-needed-to-rearrange-a-binary-string/
Author: M.R.Naganathan
*/
