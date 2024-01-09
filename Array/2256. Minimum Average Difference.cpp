/*---------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------------------------*/

class Solution {
public:
    int minimumAverageDifference(vector<int>& nums) {
        long sum = 0, init_avg = 0, end_avg = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            sum += nums[i];
        }
        long min_index = 0, left_sum = 0, min_diff = INT_MAX;
        for(int i = 0; i <= nums.size() - 1; i++){
            left_sum += nums[i];
            init_avg = left_sum/(i + 1);
            end_avg = i < nums.size() - 1 ? (sum - left_sum)/(nums.size() - i - 1) : 0;
            if(abs(init_avg - end_avg) < min_diff){
                min_index = i;
                min_diff = abs(init_avg - end_avg);
            }
        }
        return min_index;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-average-difference/
Author: M.R.Naganathan
*/
