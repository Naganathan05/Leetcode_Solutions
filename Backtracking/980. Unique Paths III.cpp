/*--------------------------------
  Time Complexity: O(4^(m * n))
  Space Complexity: O(1)
-----------------------------------*/

class Solution {
public:
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int empty = 1;
        int startX = 0, startY = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    startX = i;
                    startY = j;
                }
                empty += (grid[i][j] == 0);
            }
        }
        return DFS(grid, startX, startY, empty);
    }

    int DFS(vector<vector<int>>& grid, int i, int j, int empty) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == -1) return 0;
        if (grid[i][j] == 2) return empty == 0;

        grid[i][j] = -1;

        int paths = DFS(grid, i + 1, j, empty - 1) + DFS(grid, i - 1, j, empty - 1) +
                    DFS(grid, i, j + 1, empty - 1) + DFS(grid, i, j - 1, empty - 1);

        grid[i][j] = 0;

        return paths;
    }
};

/*
Question Link: https://leetcode.com/problems/unique-paths-iii/
Author: M.R.Naganathan
*/
