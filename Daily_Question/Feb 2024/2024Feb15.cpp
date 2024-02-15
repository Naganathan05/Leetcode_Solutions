/*----------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------------------------*/

class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        long long max_peri = 0;
        sort(nums.begin(), nums.end());
        for(int i = 0; i <= nums.size() - 1; i++){
            max_peri += nums[i];
        }
        for(int i = nums.size() - 1; i >= 0; i--){
            if(max_peri - nums[i] > nums[i]){
                return max_peri;
            }
            max_peri -= nums[i];
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/find-polygon-with-the-largest-perimeter/?envType=daily-question&envId=2024-02-15
Author: M.R.Naganathan
*/
