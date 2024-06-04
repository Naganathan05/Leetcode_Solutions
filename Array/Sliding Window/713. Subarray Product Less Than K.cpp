/*------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------------*/

class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        if(k <= 1) return 0;
        int ans = 0, pro = 1, i = 0;
        for(int j = 0; j <= nums.size() - 1; j++){
            pro *= nums[j];
            while(pro >= k){
                pro /= nums[i];
                i += 1;
            }
            ans += (j - i + 1);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/subarray-product-less-than-k/
Author: M.R.Naganathan
*/
