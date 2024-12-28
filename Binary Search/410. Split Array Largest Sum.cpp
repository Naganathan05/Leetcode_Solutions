/*---------------------------------
  Time Complexity: O(nlog(sum(n))
  Space Complexity: O(1)
------------------------------------*/

class Solution {
public:
    bool validateSplit(vector<int> &nums, int k, int largestSum){
        int currSum = 0, numSplits = 1;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(nums[i] + currSum <= largestSum) currSum += nums[i];
            else {
                numSplits += 1;
                currSum = nums[i];
            }
        }
        return numSplits <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int low = -1e9, high = 0;
        for(int i : nums){
            low = max(low, i);
            high += i;
        }

        while(low <= high){
            int mid = low + (high - low) / 2;
            if(validateSplit(nums, k, mid)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

/*
Question Link: https://leetcode.com/problems/split-array-largest-sum/
Author: M.R.Naganathan
*/
