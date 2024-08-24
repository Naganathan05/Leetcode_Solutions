/*--------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------*/

class Solution {
public:
    void DFS(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& visited, vector<pair<int, int>>& borders, int currColor) {
        visited[i][j] = true;
        bool isBorder = false;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (auto dir : directions) {
            int newX = i + dir.first;
            int newY = j + dir.second;
            
            if (newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] != currColor) isBorder = true;
            else if (!visited[newX][newY]) DFS(grid, newX, newY, visited, borders, currColor);
        }
        
        if (isBorder) borders.push_back({i, j});
        return;
    }

    vector<vector<int>> colorBorder(vector<vector<int>>& grid, int row, int col, int color) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        vector<pair<int, int>> borders;
        int currColor = grid[row][col];
        
        DFS(grid, row, col, visited, borders, currColor);
        for (auto& border : borders) grid[border.first][border.second] = color;
        return grid;
    }
};

/*
Question Link: https://leetcode.com/problems/coloring-a-border/
Author: M.R.Naganathan
*/
