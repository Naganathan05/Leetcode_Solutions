/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int xorVal = 0;
        for(int i : nums) xorVal ^= i;
        return xorVal;
    }
};

/*
Question Link: https://leetcode.com/problems/single-number/
Author: M.R.Naganathan
*/
