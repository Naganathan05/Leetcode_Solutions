/*----------------------------------
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
-------------------------------------*/

class Solution {
public:
    int maxDistance(vector<vector<int>>& grid) {
        queue<pair<int, pair<int, int>>> fifo;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        for(int i = 0; i < grid.size(); i++){
            for(int j = 0; j < grid[i].size(); j++){
                if(grid[i][j] == 1) {
                    fifo.push({0, {i, j}});
                    visited[i][j] = true;
                }
            }
        }

        if(fifo.size() == 0 || fifo.size() == grid.size() * grid[0].size()) return -1;
        int maxDistance = 0;
        while(!fifo.empty()){
            int dist = fifo.front().first;
            int x = fifo.front().second.first;
            int y = fifo.front().second.second;
            fifo.pop();

            maxDistance = max(maxDistance, dist);

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = x + dir.first;
                int newY = y + dir.second;

                if(newX >= 0 && newY >= 0 && newX < grid.size() && newY < grid[0].size() && grid[newX][newY] == 0 && !visited[newX][newY]){
                    fifo.push({dist + 1, {newX, newY}});
                    visited[newX][newY] = true;
                }
            }
        }
        return maxDistance;
    }
};

/*
Question Link: https://leetcode.com/problems/as-far-from-land-as-possible/
Author: M.R.Naganathan
*/
