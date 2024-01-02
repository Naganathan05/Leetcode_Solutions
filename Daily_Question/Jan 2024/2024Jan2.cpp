/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        unordered_map<int, int> freq;
        int row = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            freq[nums[i]]++;
            row = max(row, freq[nums[i]]);
        }

        vector<vector<int>> ans(row);
        for(auto i: freq){
            int num = i.first;
            int f = i.second;

            for(int j = 0; j < f; j++){
                ans[j].push_back(num);
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/convert-an-array-into-a-2d-array-with-conditions/description/?envType=daily-question&envId=2024-01-02
Author: M.R.Naganathan
*/
