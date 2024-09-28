/*-----------------------
  Time Complexity: O(1)
  Space Complexity: O(1)
-------------------------*/

class Solution {
public:
    int minFlips(int a, int b, int c) {
        int minFlip = 0;
        for(int i = 31; i >= 0; i--){
            int firstBit = (a >> i) & 1;
            int secondBit = (b >> i) & 1;
            int targetBit = (c >> i) & 1;
            if(targetBit) minFlip += (!firstBit && !secondBit);
            else minFlip += (firstBit + secondBit);
        }
        return minFlip;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-flips-to-make-a-or-b-equal-to-c/
Author: M.R.Naganathan
*/
