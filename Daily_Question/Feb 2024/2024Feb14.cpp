/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0);
        int pos_pointer = 0, neg_pointer = 1;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(nums[i] > 0){
                ans[pos_pointer] = nums[i];
                pos_pointer += 2;
            }
            else{
                ans[neg_pointer] = nums[i];
                neg_pointer += 2;
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/rearrange-array-elements-by-sign/description/?envType=daily-question&envId=2024-02-14
Author: M.R.Naganathan
*/
