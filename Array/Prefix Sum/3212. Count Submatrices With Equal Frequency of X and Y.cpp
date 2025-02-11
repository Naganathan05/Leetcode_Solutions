/*---------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m)
-----------------------------*/

class Solution {
public:
    int incrementSum(char c, bool& xFound) {
        if (c == 'X') {
            xFound = true;
            return 1;
        }
        if (c == 'Y') return -1;
        return 0;
    }

    int numberOfSubmatrices(vector<vector<char>>& grid) {
        int numCols = grid[0].size(), numRows = grid.size();
        vector<pair<int, bool>> prevRowSum(numCols, {0, false});

        int numSubMatrices = 0;
        for (int i = 0; i < numRows; i++) {
            int currSum = 0;
            bool xFound = false;
            for (int j = 0; j < numCols; j++) {
                currSum += incrementSum(grid[i][j], xFound);
                int subMatrixSum = currSum + prevRowSum[j].first; 
                bool xExists = xFound || prevRowSum[j].second;
                numSubMatrices += (subMatrixSum == 0 && xExists);
                prevRowSum[j] = {subMatrixSum, xExists};
            }
        }
        return numSubMatrices;
    }
};

/*
Question Link: https://leetcode.com/problems/count-submatrices-with-equal-frequency-of-x-and-y/
Author: M.R.Naganathan
*/
