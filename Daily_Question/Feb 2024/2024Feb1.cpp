/*-----------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-------------------------------------------------*/

class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for(int i = 0; i <= nums.size() - 1; i += 3){
            vector<int> row;
            int max_diff = 0;
            for(int j = i; j <= i + 1; j++){
                max_diff += (nums[j + 1] - nums[j]);
                if(max_diff > k){
                    return vector<vector<int>>();
                }
                else{
                    row.push_back(nums[j]);
                }
            }
            row.push_back(nums[i + 2]);
            ans.push_back(row);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/divide-array-into-arrays-with-max-difference/?envType=daily-question&envId=2024-02-01
Author: M.R.Naganathan
*/
