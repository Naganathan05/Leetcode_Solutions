/*------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------*/

class Solution {
public:
    int minOperations(vector<int>& nums) {
        int currMoves = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            int temp = currMoves % 2;
            if(temp != 0) nums[i] = !nums[i];
            if(nums[i] == 0) currMoves += 1;
        }
        return currMoves;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-operations-to-make-binary-array-elements-equal-to-one-ii/
Author: M.R.Naganathan
*/
