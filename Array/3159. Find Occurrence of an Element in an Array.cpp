/*-------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------------*/

class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        vector<int> ans(queries.size(), -1);
        unordered_map<int, int> freq;
        int cnt = 0;
        for(int i = 0; i <= nums.size() - 1; i++){
            if(nums[i] == x){
                cnt += 1;
                freq[cnt - 1] = i;
            }
        }
        for(int i = 0; i <= queries.size() - 1; i++){
            if(queries[i] > cnt) ans[i] = -1;
            else ans[i] = freq[queries[i] - 1];
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/find-occurrences-of-an-element-in-an-array/
Author: M.R.Naganathan
*/
