/*---------------------------------------
  Time Complexity: O(m * n * log(m * n))
  Space Complexity: O(m * n)
------------------------------------------*/

class Solution {
public:
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> safenessFactor(n, vector<int> (m, 1e9));
        queue<pair<int, int>> fifo;

        for(int i = 0; i <= n - 1; i++){
            for(int j = 0; j <= m - 1; j++){
                if(grid[i][j] == 1){
                    safenessFactor[i][j] = 0;
                    fifo.push({i, j});
                }
            }
        }

        while(!fifo.empty()){
            auto [i, j] = fifo.front();
            fifo.pop();

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = i + dir.first;
                int newY = j + dir.second;

                if(newX >= 0 && newY >= 0 && newX < n && newY < m && safenessFactor[newX][newY] > 1 + safenessFactor[i][j]){
                    safenessFactor[newX][newY] = 1 + safenessFactor[i][j];
                    fifo.push({newX, newY});
                }
            }
        }

        priority_queue<pair<int, pair<int, int>>> maxHeap;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        maxHeap.push({safenessFactor[0][0], {0, 0}});
        visited[0][0] = true;
        while(!maxHeap.empty()){
            auto [safeness, temp] = maxHeap.top();
            auto [i, j] = temp;
            maxHeap.pop();

            if(i == n - 1 && j == m - 1) return safeness;

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = i + dir.first;
                int newY = j + dir.second;

                if(newX >= 0 && newY >= 0 && newX < n && newY < m && !visited[newX][newY]){
                    int currSafe = min(safeness, safenessFactor[newX][newY]);
                    maxHeap.push({currSafe, {newX, newY}});
                    visited[newX][newY] = true;
                }
            }
        }
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-safest-path-in-a-grid/
Author: M.R.Naganathan
*/
