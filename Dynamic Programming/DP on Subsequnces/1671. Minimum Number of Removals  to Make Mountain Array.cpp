/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
        vector<int> increasingSub(nums.size(), 1);
        vector<int> decreasingSub(nums.size(), 1);

        for(int i = 0; i < nums.size(); i++){
            for(int prev = 0; prev < i; prev++){
                if(nums[i] > nums[prev]) increasingSub[i] = max(increasingSub[i], increasingSub[prev] + 1);
            }
        }

        for(int i = nums.size() - 1; i >= 0; i--){
            for(int prev = nums.size() - 1; prev > i; prev--){
                if(nums[i] > nums[prev]) decreasingSub[i] = max(decreasingSub[i], decreasingSub[prev] + 1);
            }
        }

        int maxLen = 0;
        for(int i = 0; i < nums.size(); i++){
            if(increasingSub[i] > 1 && decreasingSub[i] > 1) maxLen = max(maxLen, increasingSub[i] + decreasingSub[i] - 1);
        }
        return nums.size() - maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-removals-to-make-mountain-array/
Author: M.R.Naganathan
*/
