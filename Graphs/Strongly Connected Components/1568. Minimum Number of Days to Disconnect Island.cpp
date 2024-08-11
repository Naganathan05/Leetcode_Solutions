/*-------------------------------------
  Time Complexity: O(m * n * (m + n))
  Space Complexity: O(m + n)
----------------------------------------*/

class Solution {
public:
    void DFS(vector<vector<int>> &grid, int i, int j, vector<vector<bool>> &visited){
        visited[i][j] = true;
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto dir : directions){
            int newX = i + dir.first;
            int newY = j + dir.second;

            if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && !visited[newX][newY] && grid[newX][newY] == 1){
                DFS(grid, newX, newY, visited);
            }
        }
        return;
    }

    int GetNumIslands(vector<vector<int>> &grid){
        int numIslands = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        for(int i = 0; i <= grid.size() - 1; i++){
            for(int j = 0; j <= grid[0].size() - 1; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    numIslands += 1;
                    DFS(grid, i, j, visited);
                }
            }
        }
        return numIslands;
    }

    int minDays(vector<vector<int>>& grid) {
        if(GetNumIslands(grid) != 1) return 0;
        for(int i = 0; i <= grid.size() - 1; i++){
            for(int j = 0; j <= grid[0].size() - 1; j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(GetNumIslands(grid) != 1) return 1;
                    grid[i][j] = 1;
                }
            }
        }
        return 2;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-days-to-disconnect-island/
Author: M.R.Naganathan
*/
