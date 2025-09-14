/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> lineSweep(nums.size() + 1, 0);
        for(auto &query : queries) {
            lineSweep[query[0]] += 1;
            lineSweep[query[1] + 1] -= 1;
        }

        vector<int> prefixSum(nums.size(), 0);
        for(int i = 0; i < nums.size(); i++) {
            if(i == 0) prefixSum[i] = lineSweep[i];
            else prefixSum[i] = prefixSum[i - 1] + lineSweep[i];
            if(prefixSum[i] < nums[i]) return false;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/zero-array-transformation-i/
Author: M.R.Naganathan
*/
