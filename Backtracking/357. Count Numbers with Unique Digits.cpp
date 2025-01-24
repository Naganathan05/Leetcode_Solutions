/*----------------------------
  Time Complexity: O(2 ^ n)
  Space Complexity: O(2 ^ n)
------------------------------*/

class Solution {
public:
    int UniqueDigits(int n, int bitMask, bool isLeading) {
        if(n == 0) return 1;

        int totalNums = 0;
        for(int i = 0; i < 10; i++){
            if(i == 0 && isLeading){
                totalNums += (UniqueDigits(n - 1, bitMask, true));
                continue;
            }
            if((bitMask >> i) & 1) continue;
            int newBitMask = (bitMask | (1 << i));
            totalNums += (UniqueDigits(n - 1, newBitMask, false));
        }
        return totalNums;
    }

    int countNumbersWithUniqueDigits(int n) {
        return UniqueDigits(n, 0, true);
    }
};

/*
Question Link: https://leetcode.com/problems/count-numbers-with-unique-digits/
Author: M.R.Naganathan
*/
