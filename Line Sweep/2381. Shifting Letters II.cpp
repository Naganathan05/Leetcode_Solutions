/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    void shift(char& ch, int shift){
        int netShift = (shift % 26 + 26) % 26;
        ch = 'a' + (ch - 'a' + netShift) % 26;
    }

    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> prefixShifts(s.length() + 1, 0);
        for(int i = 0; i <= shifts.size() - 1; i++){
            int currShift = shifts[i][2] == 0 ? -1 : 1;
            prefixShifts[shifts[i][0]] += currShift;
            prefixShifts[shifts[i][1] + 1] -= currShift;
        }
        
        for(int i = 0; i <= prefixShifts.size() - 1; i++){
            if(i != 0) prefixShifts[i] += prefixShifts[i - 1];
            shift(s[i], prefixShifts[i]);
        }
        return s;
    }
};

/*
Question Link: https://leetcode.com/problems/shifting-letters-ii/
Author: M.R.Naganathan
*/
