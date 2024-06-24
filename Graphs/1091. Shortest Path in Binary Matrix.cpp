/*------------------------------------
Method - Breadth First Search - [BFS]
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
---------------------------------------*/

class Solution {
public:
    int BFS(vector<vector<int>> &grid, int start_x, int start_y){
        int pathLen = 0;
        queue<pair<int, int>> fifo;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        visited[start_x][start_y] = true;
        fifo.push({start_x, start_y});
        while(!fifo.empty()){
            int size = fifo.size();
            pathLen += 1;
            for(int cnt = 0; cnt <= size - 1; cnt++){
                auto currCoord = fifo.front();
                fifo.pop();
                int i = currCoord.first;
                int j = currCoord.second;

                if(i == grid.size() - 1 && j == grid[i].size() - 1) return pathLen;

                if(i - 1 >= 0 && !visited[i - 1][j] && grid[i - 1][j] == 0){
                    fifo.push({i - 1, j});
                    visited[i - 1][j] = true;
                }
                if(j - 1 >= 0 && !visited[i][j - 1] && grid[i][j - 1] == 0){
                    fifo.push({i, j - 1});
                    visited[i][j - 1] = true;
                }
                if(i + 1 < grid.size() && !visited[i + 1][j] && grid[i + 1][j] == 0){
                    fifo.push({i + 1, j});
                    visited[i + 1][j] = true;
                }
                if(j + 1 < grid[0].size() && !visited[i][j + 1] && grid[i][j + 1] == 0){
                    fifo.push({i, j + 1});
                    visited[i][j + 1] = true;
                }

                if(i - 1 >= 0 && j - 1 >= 0 && !visited[i - 1][j - 1] && grid[i - 1][j - 1] == 0){
                    fifo.push({i - 1, j - 1});
                    visited[i - 1][j - 1] = true;
                }
                if(i - 1 >= 0 && j + 1 < grid[0].size() && !visited[i - 1][j + 1] && grid[i - 1][j + 1] == 0){
                    fifo.push({i - 1, j + 1});
                    visited[i - 1][j + 1] = true;
                }
                if(i + 1 < grid.size() && j - 1 >= 0 && !visited[i + 1][j - 1] && grid[i + 1][j - 1] == 0){
                    fifo.push({i + 1, j - 1});
                    visited[i + 1][j - 1] = true;
                }
                if(i + 1 < grid.size() && j + 1 < grid[0].size() && !visited[i + 1][j + 1] && grid[i + 1][j + 1] == 0){
                    fifo.push({i + 1, j + 1});
                    visited[i + 1][j + 1] = true;
                }
            }
        }
        return -1;
    }

    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[0][0] != 0) return -1;
        return BFS(grid, 0, 0);
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-path-in-binary-matrix/
Author: M.R.Naganathan
*/
