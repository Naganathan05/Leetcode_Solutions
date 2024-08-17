/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxLen = 0, numZeroes = 0, i = 0;
        for(int j = 0; j <= nums.size() - 1; j++){
            numZeroes += (nums[j] == 0);
            while(numZeroes > 1){
                numZeroes -= (nums[i] == 0);
                i += 1;
            }
            maxLen = max(maxLen, (j - i + 1));
        }
        if(maxLen == 0) return 0;
        return maxLen - 1;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/
Author: M.R.Naganathan
*/
