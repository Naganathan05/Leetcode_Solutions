/*---------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(m)
-----------------------------*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        
        int numSubMatrices = 0;
        vector<long long> prevRowPrefixSum(m, 0);
        for(int i = 0; i < n; i++) {
            long long currRowSum = 0;
            for(int j = 0; j < m; j++) {
                currRowSum += grid[i][j];
                prevRowPrefixSum[j] += currRowSum;
                if(prevRowPrefixSum[j] > k) break;
                numSubMatrices += 1;
            }
        }
        return numSubMatrices;
    }
};

/*----------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
------------------------------*/

class Solution {
public:
    int countSubmatrices(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();

        int numSubMatrices = 0;
        vector<vector<long long>> prefixSumGrid(n, vector<long long> (m, 0));

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                prefixSumGrid[i][j] = grid[i][j];
                if(i > 0) prefixSumGrid[i][j] += prefixSumGrid[i - 1][j];
                if(j > 0) prefixSumGrid[i][j] += prefixSumGrid[i][j - 1];
                if(i > 0 && j > 0) prefixSumGrid[i][j] -= prefixSumGrid[i - 1][j - 1];
                if(prefixSumGrid[i][j] > k) break;
                numSubMatrices += 1;
            }
        }
        return numSubMatrices;
    }
};

/*
Question Link: https://leetcode.com/problems/count-submatrices-with-top-left-element-and-sum-less-than-k/
Author: M.R.Naganathan
*/
