/*-------------------------
  Time Complexity: O(logn)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int st = 0, en = nums.size() - 1, mid, start_ind, end_ind;
        vector<int> ans;
        if(binarySearch(nums, target) == -1){
            ans.push_back(-1);
            ans.push_back(-1);
            return ans;
        }
        while(st <= en){
            mid = (st + en)/2;
            if(nums[mid] >= target){
                en = mid - 1;
                start_ind = mid;
            }
            else if(nums[mid] < target){
                st = mid + 1;
            }
        }
        st = 0;
        en = nums.size() - 1;
        while(st <= en){
            mid = (st + en)/2;
            if(nums[mid] <= target){
                st = mid + 1;
                end_ind = mid;
            }
            else if(nums[mid] > target){
                en = mid - 1;
            }
        }
        ans.push_back(start_ind);
        ans.push_back(end_ind);
        return ans;
    }

    int binarySearch(vector<int>& nums, int target){
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
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-first-and-last-position-of-element-in-sorted-array/
Author: M.R.Naganathan
*/
