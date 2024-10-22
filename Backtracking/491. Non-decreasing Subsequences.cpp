/*---------------------------
  Time Complexity: O(2 ^ n)
  Space Complexity: O(2 ^ n)
------------------------------*/

class Solution {
public:
    void generateSubsequence(vector<int> &nums, int i, int prev, vector<int> &currList, set<vector<int>> &ans){
        if(i == nums.size()){
            if(currList.size() >= 2) ans.insert(currList);
            return;
        }

        if(prev == -1 || nums[prev] <= nums[i]){
            currList.push_back(nums[i]);
            generateSubsequence(nums, i + 1, i, currList, ans);
            currList.pop_back();
        }
        generateSubsequence(nums, i + 1, prev, currList, ans);
        return;
    }

    vector<vector<int>> findSubsequences(vector<int>& nums) {
        vector<int> currList;
        set<vector<int>> ans;
        generateSubsequence(nums, 0, -1, currList, ans);
        return vector(ans.begin(), ans.end());
    }
};

/*
Question Link: https://leetcode.com/problems/non-decreasing-subsequences/
Author: M.R.Naganathan
*/
