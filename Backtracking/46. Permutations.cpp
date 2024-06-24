/*-----------------------------------
  Time Complexity: O(n!)
  Space Complexity: O(n) + O(n)
-------------------------------------*/

class Solution {
public:
    void generate(vector<int> &nums, vector<vector<int>> &permutation, vector<int> &currList, vector<bool> &visited){
        if(currList.size() == nums.size()){
            permutation.push_back(currList);
            return;
        }

        for(int i = 0; i <= nums.size() - 1; i++){
            if(visited[i]) continue;
            visited[i] = true;
            currList.push_back(nums[i]);
            generate(nums, permutation, currList, visited);
            currList.pop_back();
            visited[i] = false;
        }
        return;
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> permutation;
        vector<int> currList;
        vector<bool> visited(nums.size(), false);
        generate(nums, permutation, currList, visited);
        return permutation;
    }
};

/*
Question Link: https://leetcode.com/problems/permutations/
Author: M.R.Naganathan
*/
