/*---------------------------
  Time Complexity: O(2 ^ n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    void Combination(vector<int> &candidates, int start, int target, int currSum, vector<int> &currList, vector<vector<int>> &ans) {
        if(currSum == target) {
            ans.push_back(currList);
            return;
        }

        int prev = -1;
        for(int j = start; j < candidates.size(); j++) {
            if(candidates[j] + currSum > target) break;
            if(prev == candidates[j]) continue;

            currList.push_back(candidates[j]);
            Combination(candidates, j + 1, target, currSum + candidates[j], currList, ans);
            currList.pop_back();
            prev = candidates[j];
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currList;
        sort(candidates.begin(), candidates.end());
        Combination(candidates, 0, target, 0, currList, ans);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/combination-sum-ii/
Author: M.R.Naganathan
*/
