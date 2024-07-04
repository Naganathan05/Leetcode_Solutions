/*---------------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
-----------------------------------*/

class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);

        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        queue<pair<int, pair<int, int>>> fifo;

        // Push all the Sources of BFS into the Queue.
        for(int i = 0; i <= visited.size() - 1; i++){
            for(int j = 0; j <= visited[i].size() - 1; j++){
                if(grid[i][j] == 2){
                    fifo.push({0, {i, j}});
                    visited[i][j] = true;
                }
            }
        }
        
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int time = 0;
        while(!fifo.empty()){
            int t = fifo.front().first;
            int x = fifo.front().second.first;
            int y = fifo.front().second.second;
            fifo.pop();
            time = max(time, t);

            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;
                if(newX < grid.size() && newX >= 0 && newY < grid[0].size() && newY >= 0 && !visited[newX][newY] && grid[newX][newY] == 1){
                    visited[newX][newY] = true;
                    fifo.push({t + 1, {newX, newY}});
                }
            }
        }

        for(int i = 0; i <= grid.size() - 1; i++){
            for(int j = 0; j <= grid[i].size() - 1; j++){
                if(grid[i][j] == 1 && !visited[i][j]) return -1;
            }
        }
        return time;
    }
};

/*
Question Link: https://leetcode.com/problems/rotting-oranges/
Author: M.R.Naganathan
*/
