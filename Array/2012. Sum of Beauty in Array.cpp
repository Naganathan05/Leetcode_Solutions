/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------------------------------*/

class Solution {
public:
    int sumOfBeauties(vector<int>& nums) {
        stack<int> right_min;
        int min_element = INT_MAX;
        for(int i = nums.size() - 1; i >= 2; i--){
            if(min_element > nums[i]){
                min_element = nums[i];
            }
            right_min.push(min_element);
        }
        int left_max = nums[0], beauty_score = 0;
        for(int i = 1; i <= nums.size() - 2; i++){
            if(left_max < nums[i] && nums[i] < right_min.top()){
                beauty_score += 2;
            }
            else if(nums[i - 1] < nums[i] && nums[i] < nums[i + 1]){
                beauty_score += 1;
            }
            right_min.pop();
            left_max = max(left_max, nums[i]);
        }
        return beauty_score;
    }
};

/*
Question Link: https://leetcode.com/problems/sum-of-beauty-in-the-array/
Author: M.R.Naganathan
*/
