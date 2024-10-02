/*---------------------------
  Time Complexity: O(2 ^ n)
  Space Complexity: O(2 ^ n)
------------------------------*/

class Solution {
public:
    void generate(int n, int k, int i, vector<int> &currList, vector<vector<int>> &combinations){
        if(k == 0 && n == 0){
            combinations.push_back(currList);
            return;
        }
        if(n <= 0 || k <= 0 || i >= 10) return;

        currList.push_back(i);
        generate(n - i, k - 1, i + 1, currList, combinations);
        currList.pop_back();
        generate(n, k, i + 1, currList, combinations);
        return;
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> currList;
        vector<vector<int>> combinations;
        generate(n, k, 1, currList, combinations);
        return combinations;
    }
};

/*
Question Link: https://leetcode.com/problems/combination-sum-iii/
Author: M.R.Naganathan
*/
