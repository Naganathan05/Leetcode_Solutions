/*---------------------------------------
Method: Dijkstra's Algorithm
  Time Complexity: O(n * m * log(m * n))
  Space Complexity: O(n * m)
------------------------------------------*/

class Solution {
public:
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({grid[0][0], {0, 0}});
        dist[0][0] = grid[0][0];

        while(!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int maxHeight = pq.top().first;
            pq.pop();

            if(i == n - 1 && j == m - 1) return max(grid[i][j], maxHeight);

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = i + dir.first;
                int newY = j + dir.second;

                if(newX >= 0 && newY >= 0 && newX < n && newY < m){
                    int newHeight = max(maxHeight, grid[newX][newY]);
                    if(dist[newX][newY] > newHeight){
                        dist[newX][newY] = newHeight;
                        pq.push({newHeight, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/swim-in-rising-water/description/
Author: M.R.Naganathan
*/
