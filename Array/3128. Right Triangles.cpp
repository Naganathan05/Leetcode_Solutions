/*----------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------*/

class Solution {
public:
    long long numberOfRightTriangles(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        vector<int> rowOnes(m, 0);
        vector<int> colOnes(n, 0);

        for(int i = 0; i <= m - 1; i++){
            for(int j = 0; j <= n - 1; j++){
                rowOnes[i] += (grid[i][j] == 1);
                colOnes[j] += (grid[i][j] == 1);
            }
        }

        long long numTriangles = 0;
        for(int i = 0; i <= m - 1; i++){
            for(int j = 0; j <= n - 1; j++){
                if(grid[i][j] == 0) continue;
                numTriangles += ((rowOnes[i] - 1) * (colOnes[j] - 1));
            }
        }
        return numTriangles;
    }
};

/*
Question Link: https://leetcode.com/problems/right-triangles/
Author: M.R.Naganathan
*/
