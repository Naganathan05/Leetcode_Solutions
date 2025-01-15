/*-----------------------
  Time Complexity: O(1)
  Space Complexity: O(1)
-------------------------*/

class Solution {
public:
    int minimizeXor(int num1, int num2) {
        int ans = 0;

        int maxSetBits = __builtin_popcount(num2), numSetBits = 0;
        int currBit = 31;

        while(numSetBits < maxSetBits){
            if(((num1 >> currBit) & 1) || (maxSetBits - numSetBits > currBit)){
                ans |= (1 << currBit);
                numSetBits += 1;
            }
            currBit -= 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/minimize-xor/
Author: M.R.Naganathan
*/
