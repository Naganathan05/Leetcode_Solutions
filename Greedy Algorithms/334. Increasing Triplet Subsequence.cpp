/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------*/

class Solution {
public:
    bool increasingTriplet(vector<int>& nums) {

        if(nums.size() <= 2) return false;

        int smallest = INT_MAX;
        int secondSmallest = INT_MAX;

        for(int i = 0; i <= nums.size() - 1; i++){
            int currNum = nums[i];
            if(currNum > smallest) return true;
            if(currNum > secondSmallest) smallest = currNum;
            else secondSmallest = currNum;
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/increasing-triplet-subsequence/
Author: M.R.Naganathan
*/
