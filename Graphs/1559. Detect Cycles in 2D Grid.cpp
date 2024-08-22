/*--------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------*/

class Solution {
public:
    bool containsCycle(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (!visited[i][j]) {
                    if (checkCycle(grid, {-1, -1}, i, j, visited, 1)) return true;
                }
            }
        }
        return false;
    }

    bool checkCycle(vector<vector<char>> &grid, pair<int, int> parent, int i, int j, vector<vector<bool>> &visited, int currLength) {
        visited[i][j] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (auto dir : directions) {
            int newX = i + dir.first;
            int newY = j + dir.second;

            if (newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size()) {
                if (!(parent.first == newX && parent.second == newY)) {
                    if (grid[newX][newY] == grid[i][j] && visited[newX][newY] && currLength >= 4) return true;
                    if (grid[newX][newY] == grid[i][j] && !visited[newX][newY]) {
                        if (checkCycle(grid, {i, j}, newX, newY, visited, currLength + 1)) return true;
                    }
                }
            }
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/detect-cycles-in-2d-grid/
Author: M.R.Naganathan
*/
