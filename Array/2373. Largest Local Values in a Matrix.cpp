/*---------------------------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
-----------------------------------------------*/

class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        vector<vector<int>> ans(grid.size() - 2, vector<int>(grid.size() - 2));

        for(int i = 1; i <= grid.size() - 2; i++) {
            for(int j = 1; j <= grid.size() - 2; j++) {
                int currMax = 0;

                for(int k = i - 1; k <= i + 1; k++) {
                    for(int l = j - 1; l <= j + 1; l++) {
                        currMax = max(currMax, grid[k][l]);
                    }
                }

                ans[i - 1][j - 1] = currMax;
            }
        }

        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/largest-local-values-in-a-matrix/
Author: M.R.Naganathan
*/
