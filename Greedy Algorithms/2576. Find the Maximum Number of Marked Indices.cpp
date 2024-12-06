/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int i = 0, j = (n + 1) / 2, numMarked = 0;
        while(i < n/2 && j < n){
            if(nums[i] * 2 <= nums[j]){
                i += 1;
                numMarked += 2;
            }
            j += 1;
        }
        return numMarked;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-maximum-number-of-marked-indices/
Author: M.R.Naganathan
*/
