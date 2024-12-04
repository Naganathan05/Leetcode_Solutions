/*---------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    bool makeSubsequence(string &str1, string &str2, int i, int j){
        if(j == str2.length()) return true;
        if(i == str1.length()) return false;

        int asciiDiff = ((int)str2[j] - (int)str1[i] + 26) % 26;
        if(abs(asciiDiff) <= 1) return makeSubsequence(str1, str2, i + 1, j + 1);
        return makeSubsequence(str1, str2, i + 1, j);
    }

    bool canMakeSubsequence(string str1, string str2) {
        return makeSubsequence(str1, str2, 0, 0);
    }
};

/*
Question Link: https://leetcode.com/problems/make-string-a-subsequence-using-cyclic-increments/
Author: M.R.Naganathan
*/
