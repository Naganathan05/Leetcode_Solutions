/*--------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        int minVal = 1e9;
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(nums[low] <= nums[mid]){
                minVal = min(minVal, nums[low]);
                low = mid + 1;
            }
            else{
                minVal = min(minVal, nums[mid]);
                high = mid - 1;
            }
        }
        return minVal;
    }
};

/*
Question Link: https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
Author: M.R.Naganathan
*/
