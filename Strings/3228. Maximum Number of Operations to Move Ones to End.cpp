/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int maxOperations(string s) {
        int numOnes = 0;
        int totalOperations = 0;
        int i = 0;

        while (i < s.length()) {
            if (s[i] == '1') {
                numOnes += 1;
                i += 1;
            }
            else{
                while (i < s.length() && s[i] == '0') {
                    i += 1;
                }
                totalOperations += numOnes;
            }
        }
        return totalOperations;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-operations-to-move-ones-to-the-end/description/
Author: M.R.Naganathan
*/
