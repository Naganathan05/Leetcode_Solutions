/*------------------------
  Time Complexity: O(1)
  Space Complexity: O(1)
---------------------------*/

class Solution {
public:
    int getSum(int a, int b) {
        int sum = 0, carry = 0;
        for(int i = 0; i <= 31; i++){
            int firstBit = (a >> i) & 1;
            int secondBit = (b >> i) & 1;
            int sumBit = 0;
            if(carry){
                if(firstBit && secondBit) sumBit = 1;
                else if(!firstBit && !secondBit){
                    sumBit = 1;
                    carry = 0;
                }
            }
            else{
                if(firstBit && secondBit) carry = 1;
                else if(firstBit || secondBit) sumBit = 1;
            }
            sum |= (sumBit << i);
        }
        return sum;
    }
};

/*
Question Link: https://leetcode.com/problems/sum-of-two-integers/
Author: M.R.Naganathan
*/
