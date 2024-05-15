/*---------------------------------------
  Time Complexity: O(2^n)
  Space Complexity: O(n)
------------------------------------------*/

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> ans;
        vector<int> currList;
        c(1, n, k, ans, currList);
        return ans;
    }

    void c(int i, int n, int k, vector<vector<int>> &ans, vector<int>& currList){
        if(currList.size() == k){
            ans.push_back(currList);
            return;
        }
        if(i > n) return;
        currList.push_back(i);
        c(i + 1, n, k, ans, currList);
        currList.pop_back();
        c(i + 1, n, k, ans, currList);
        return;
    }
};

/*
Question Link: https://leetcode.com/problems/combinations/
Author: M.R.Naganathan
*/
