/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------------------------*/

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int zero_count = 0, one_count = 0, two_count = 0;
        for(int i : nums){
            if(i == 0){
                zero_count += 1;
            }
            else if(i == 1){
                one_count += 1;
            }
            else{
                two_count += 1;
            }
        }

        for(int i = 0; i <= nums.size() - 1; i++){
            if(zero_count){
                nums[i] = 0;
                zero_count -= 1;
            }
            else if(one_count){
                nums[i] = 1;
                one_count -= 1;
            }
            else{
                nums[i] = 2;
            }
        }
    }
};

/*
Question Link: https://leetcode.com/problems/sort-colors/
Author: M.R.Naganathan
*/
