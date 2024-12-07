/*---------------------------
  Time Complexity: O(nlogn)  
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    bool validateMax(vector<int> &nums, int &currMax, int &maxOperations){
        int numOperations = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(nums[i] > currMax) numOperations += (nums[i] - 1)/currMax;
        }
        return numOperations <= maxOperations;
    }

    int minimumSize(vector<int>& nums, int maxOperations) {
        int low = 1, high = 0, ans = -1;
        for(int i : nums) high = max(high, i);
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(validateMax(nums, mid, maxOperations)){
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-limit-of-balls-in-a-bag/
Author: M.R.Naganathan
*/
