/*---------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> prefixSum;
        prefixSum[0] = -1;
        int currSum = 0, maxLen = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(nums[i] == 1) currSum += 1;
            else currSum -= 1;

            if(prefixSum.find(currSum) != prefixSum.end()) maxLen = max(maxLen, (i - prefixSum[currSum]));
            else prefixSum[currSum] = i;
        }
        return maxLen;
    }
};

/*
Question Link: https://leetcode.com/problems/contiguous-array/
Author: M.R.Naganathan
*/
