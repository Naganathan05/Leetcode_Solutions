/*--------------------------------------
  Time Complexity: O(max(start, goal))
  Space Complexity: O(1)
-----------------------------------------*/

class Solution {
public:
    int minBitFlips(int start, int goal) {
        int numChanges = 0;
        int xorVal = start ^ goal;
        while(xorVal > 0){
            numChanges += (xorVal & 1);
            xorVal >>= 1;
        }
        return numChanges;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-bit-flips-to-convert-number/
Author: M.R.Naganathan
*/
