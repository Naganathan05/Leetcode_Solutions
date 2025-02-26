/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    int KadanesAlgo(vector<int> &nums){
        int maxGlobalSum = nums[0], currSum = nums[0];
        for(int i = 1; i < nums.size(); i++){
            currSum = max(currSum + nums[i], nums[i]);
            maxGlobalSum = max(maxGlobalSum, currSum);
        }
        return maxGlobalSum;
    }

    int maxAbsoluteSum(vector<int>& nums) {
        int maxSum = KadanesAlgo(nums);
        for(int i = 0; i < nums.size(); i++) nums[i] = -nums[i];
        int minSum = KadanesAlgo(nums);
        return max(maxSum, minSum);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-absolute-sum-of-any-subarray/
Author: M.R.Naganathan
*/
