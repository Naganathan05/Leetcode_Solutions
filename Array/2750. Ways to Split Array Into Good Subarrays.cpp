/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        int n = nums.size();
        int firstOne = -1, lastOne = -1;
        
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0) continue;
            firstOne = (firstOne == -1) ? i : firstOne;
            lastOne = i;
        }
        
        if (firstOne == -1) return 0;
        long long numSplits = 1;
        int prevOne = firstOne;

        for (int i = firstOne + 1; i <= lastOne; i++) {
            if (nums[i] == 0) continue;
            numSplits = (numSplits * (i - prevOne)) % mod;
            prevOne = i;
        }
        return numSplits;
    }
};

/*
Question Link: https://leetcode.com/problems/ways-to-split-array-into-good-subarrays/
Author: M.R.Naganathan
*/
