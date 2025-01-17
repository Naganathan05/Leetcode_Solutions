/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    bool doesValidArrayExist(vector<int>& derived) {
        int totalXOR = 0;
        for(int i : derived) totalXOR ^= i;
        return totalXOR == 0;
    }
};

/*
Qustion Link: https://leetcode.com/problems/neighboring-bitwise-xor/
Author: M.R.Naganathan
*/
