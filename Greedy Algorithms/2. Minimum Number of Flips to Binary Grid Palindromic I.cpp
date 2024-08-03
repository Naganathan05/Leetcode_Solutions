/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int minFlips(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int rowFlips = 0;
        for (int i = 0; i < m; ++i) {
            rowFlips += minFlipsForPalindromicLine(grid[i]);
        }
        
        int colFlips = 0;
        for (int j = 0; j < n; ++j) {
            vector<int> col(m);
            for (int i = 0; i < m; ++i) {
                col[i] = grid[i][j];
            }
            colFlips += minFlipsForPalindromicLine(col);
        }
        return min(rowFlips, colFlips);
    }

    int minFlipsForPalindromicLine(const vector<int>& line) {
        int flips = 0;
        int i = 0, j = line.size() - 1;
        while (i < j) {
            flips += (line[i] != line[j]);
            i += 1;
            j -= 1;
        }
        return flips;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-flips-to-make-binary-grid-palindromic-i/
Author: M.R.Naganathan
*/
