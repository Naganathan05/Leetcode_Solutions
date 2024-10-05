/*--------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int st = 0, en = nums.size() - 1, mid;

        while(st <= en){
            mid = (st + en)/2;

            if(nums[mid] == target){
                return mid;
            }
            else if(nums[mid] > target){
                en = mid - 1;
            }
            else{
                st = mid + 1;
            }
        }
        return st;
    }
};

/*
Question Link: https://leetcode.com/problems/search-insert-position/
Author: M.R.Naganathan
*/
