/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long numPairs = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size() - 1; i++){
            int lowerBound = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            int upperBound = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            numPairs += (upperBound - lowerBound);
        }
        return numPairs;
    }
};

/*
Question Link: https://leetcode.com/problems/count-the-number-of-fair-pairs/
Author: M.R.Naganathan
*/
