/*---------------------------------------
  Time Complexity: O(n^target)
  Space Complexity: O(n * target)
-----------------------------------------*/

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> currList;
        combination(candidates, 0, target, ans, currList);
        return ans;
    }

    void combination(vector<int> &candidates, int i, int target, vector<vector<int>> &ans, vector<int>& currList){
        if(target == 0){
            ans.push_back(currList);
            return;
        }
        if(i == candidates.size() || target < 0) return;

        currList.push_back(candidates[i]);
        combination(candidates, i, target - candidates[i], ans, currList);
        currList.pop_back();
        combination(candidates, i + 1, target, ans, currList);
        return;

    }
};

/*
Question Link: https://leetcode.com/problems/combination-sum/
Author: M.R.Naganathan
*/
