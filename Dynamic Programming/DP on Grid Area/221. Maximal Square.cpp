/*---------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
-----------------------------*/

class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();

        int maxSquareLen = 0;

        vector<vector<int>> squareGrid(n, vector<int> (m, 0));
        for(int i = 0; i < n; i++) {
            squareGrid[i][0] = (matrix[i][0] == '1');
            if(maxSquareLen == 0) maxSquareLen = (matrix[i][0] == '1');
        }

        for(int i = 0; i < m; i++) {
            squareGrid[0][i] = (matrix[0][i] == '1');
            if(maxSquareLen == 0) maxSquareLen = (matrix[0][i] == '1');
        }

        for(int i = 1; i < n; i++) {
            for(int j = 1; j < m; j++) {
                if(matrix[i][j] != '1') continue;
                int leftMax = squareGrid[i][j - 1];
                int topMax = squareGrid[i - 1][j];
                int diagonalMax = squareGrid[i - 1][j - 1];
                int currSquareLen = min({leftMax, topMax, diagonalMax});

                maxSquareLen = max(maxSquareLen, currSquareLen + 1);
                squareGrid[i][j] = currSquareLen + 1;
            }
        }
        return (maxSquareLen * maxSquareLen);
    }
};

/*
Question Link: https://leetcode.com/problems/maximal-square/
Author: M.R.Naganathan
*/
