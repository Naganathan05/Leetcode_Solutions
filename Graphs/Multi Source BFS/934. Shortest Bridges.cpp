/*----------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------------*/

class Solution {
public:
    void DFS(vector<vector<int>> &grid, queue<pair<int, pair<int, int>>> &fifo, vector<vector<bool>> &visited, int i, int j){
        visited[i][j] = true;
        fifo.push({0, {i, j}});
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for(auto dir : directions){
            int newX = i + dir.first;
            int newY = j + dir.second;

            if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == 1 && !visited[newX][newY]){
                DFS(grid, fifo, visited, newX, newY);
            }
        }
    }

    int shortestBridge(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, pair<int, int>>> fifo;
        bool found = false;

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 1 && !found){
                    DFS(grid, fifo, visited, i, j);
                    found = true;
                    break;
                }
            }
            if (found) break;
        }

        while(!fifo.empty()){
            int x = fifo.front().second.first;
            int y = fifo.front().second.second;
            int dist = fifo.front().first;
            fifo.pop();

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY]){
                    if(grid[newX][newY] == 0){
                        visited[newX][newY] = true;
                        fifo.push({dist + 1, {newX, newY}});
                    } else if(grid[newX][newY] == 1){
                        return dist;
                    }
                }
            }
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-bridge/
Author: M.R.Naganathan
*/
