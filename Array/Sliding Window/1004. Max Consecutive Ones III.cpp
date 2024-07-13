/*-----------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------------*/

class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int numZeroes = 0, maxLen = 0, i = 0;
        for(int j = 0; j <= nums.size() - 1; j++){
            numZeroes += (nums[j] == 0);
            while(numZeroes > k){
                numZeroes -= (nums[i] == 0);
                i += 1;
            }
            maxLen = max(maxLen, (j - i + 1));
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/max-consecutive-ones-iii/
Author: M.R.Naganathan
*/
