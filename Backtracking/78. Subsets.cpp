/*---------------------------------------
  Time Complexity: O(2^n)
  Space Complexity: O(n)
------------------------------------------*/

class Solution {
public:
    void generate(vector<int> &nums, vector<vector<int>> &ans, int i, vector<int> currList){
        if(i == nums.size()) return;

        generate(nums, ans, i + 1, currList);
        currList.push_back(nums[i]);
        ans.push_back(currList);
        generate(nums, ans, i + 1, currList);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> currList;
        ans.push_back(currList);
        generate(nums, ans, 0, currList);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/subsets/
Author: M.R.Naganathan
*/
