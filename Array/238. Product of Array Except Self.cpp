/*------------------------------------------------------------
  Time Complexity: O(n)  => n:Number of Elements in the Array
  Space Complexity: O(n)
--------------------------------------------------------------*/

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int> left;
        int pro = 1;
        left.push_back(pro);
        for(int i = 1; i <= nums.size() - 1; i++){
            pro *= nums[i - 1];
            left.push_back(pro);
        }
        pro = 1;
        int j = left.size() - 2;
        for(int i = nums.size() - 2; i >= 0; i--){
            pro *= nums[i + 1];
            left[j] *= pro;
            j--;
        }
        return left;
    }
};

/*
Question Link: https://leetcode.com/problems/product-of-array-except-self/description/
Author: M.R.Naganathan
*/
