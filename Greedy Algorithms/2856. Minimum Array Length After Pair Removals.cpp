/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------*/

class Solution {
public:
    int minLengthAfterRemovals(vector<int>& nums) {
        int i = 0, j = (nums.size() + 1) / 2, minLen = nums.size();
        while(i < nums.size() / 2 && j < nums.size()){
            if(nums[i] < nums[j]){
                minLen -= 2;
                i += 1;
                j += 1;
            }
            else j += 1;
        }
        return minLen;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-array-length-after-pair-removals/
Author: M.R.Naganathan
*/
