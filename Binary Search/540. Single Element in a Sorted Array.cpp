/*---------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0, high = nums.size() - 1;
        while (low <= high) {
            int mid = low + (high - low) / 2;

            if ((mid == 0 || nums[mid] != nums[mid - 1]) &&
                (mid == nums.size() - 1 || nums[mid] != nums[mid + 1])) {
                return nums[mid];
            }

            int leftSectionLen = mid - low;
            int rightSectionLen = high - mid;

            if (mid > 0 && nums[mid] == nums[mid - 1]) {
                if (leftSectionLen % 2 == 0) high = mid - 2;
                else low = mid + 1;
            }
            else if (mid + 1 < nums.size() && nums[mid] == nums[mid + 1]) {
                if (rightSectionLen % 2 == 0) low = mid + 2;
                else high = mid - 1;
            }
        }
        unreachable();
    }
};

/*
Question Link: https://leetcode.com/problems/single-element-in-a-sorted-array/
Author: M.R.Naganathan
*/
