/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    bool checkTransformation(vector<int> &nums, vector<vector<int>> &queries, int maxOps) {
        vector<int> lineSweep(nums.size() + 1, 0);
        for(int i = 0; i < maxOps; i++){
            lineSweep[queries[i][0]] -= queries[i][2];
            lineSweep[queries[i][1] + 1] += queries[i][2];
        }

        for(int i = 0; i < nums.size(); i++){
            if(i != 0) lineSweep[i] += lineSweep[i - 1];
            if(nums[i] + lineSweep[i] > 0) return false;
        }
        return true;
    }

    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        int low = 0, high = queries.size();
        while(low <= high){
            int mid = low + (high - low) / 2;
            if(checkTransformation(nums, queries, mid)) high = mid - 1;
            else low = mid + 1;
        }
        return (high == queries.size()) ? -1 : low;
    }
};

/*
Question Link: https://leetcode.com/problems/zero-array-transformation-ii/
Author: M.R.Naganathan
*/
