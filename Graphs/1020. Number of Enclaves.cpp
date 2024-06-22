/*---------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------------------*/

class Solution {
public:
    void BFS(vector<vector<int>> &grid, int start_i, int start_j, vector<vector<bool>> &visited){
        queue<pair<int, int>> q;
        q.push({start_i, start_j});
        visited[start_i][start_j] = true;
        while(!q.empty()){
            auto land = q.front();
            int i = land.first;
            int j = land.second;
            q.pop();

            if(i + 1 < grid.size() && grid[i + 1][j] == 1 && !visited[i + 1][j]){
                q.push({i + 1, j});
                visited[i + 1][j] = true;
            }
            if(j + 1 < grid[0].size() && grid[i][j + 1] == 1 && !visited[i][j + 1]){
                q.push({i, j + 1});
                visited[i][j + 1] = true;
            }
            if(i - 1 >= 0 && grid[i - 1][j] == 1 && !visited[i - 1][j]){
                q.push({i - 1, j});
                visited[i - 1][j] = true;
            }
            if(j - 1 >= 0 && grid[i][j - 1] == 1 && !visited[i][j - 1]){
                q.push({i, j - 1}); 
                visited[i][j - 1] = true;
            }
        }
        return;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int lockedLand = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if ((i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) && grid[i][j] == 1 && !visited[i][j]) {
                    BFS(grid, i, j, visited);
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1 && !visited[i][j]) {
                    lockedLand += 1;
                }
            }
        }

        return lockedLand;
    }
};

/*--------------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(m * n)
  Space Complexity: O(max(m, n))
----------------------------------------------*/

class Solution {
public:
    bool Enclaves(vector<vector<int>> &grid, int i, int j) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size()) return true;
        if (grid[i][j] != 1) return false;

        grid[i][j] = 0;

        bool up = Enclaves(grid, i - 1, j);
        bool left = Enclaves(grid, i, j - 1);
        bool right = Enclaves(grid, i, j + 1);
        bool down = Enclaves(grid, i + 1, j);

        return up || left || right || down;
    }

    int numEnclaves(vector<vector<int>>& grid) {
        int lockedLand = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if ((i == 0 || j == 0 || i == grid.size() - 1 || j == grid[0].size() - 1) && grid[i][j] == 1) {
                    Enclaves(grid, i, j);
                }
            }
        }

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] == 1) {
                    lockedLand += 1;
                }
            }
        }

        return lockedLand;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-enclaves/description/
Author: M.R.Naganathan
*/
