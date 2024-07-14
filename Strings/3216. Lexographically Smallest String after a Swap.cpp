/*---------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    string getSmallestString(string s) {
        for(int i = 0; i < s.length() - 1; i++){
            if ((s[i] - '0') % 2 == (s[i + 1] - '0') % 2){
                if(s[i] > s[i + 1]){
                    swap(s[i], s[i + 1]);
                    return s;
                }
            }
        }
        return s;
    }
};

/*
Question Link: https://leetcode.com/problems/lexicographically-smallest-string-after-a-swap/
Author: M.R.Naganathan
*/
