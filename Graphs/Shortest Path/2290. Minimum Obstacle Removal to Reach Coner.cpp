/*----------------------------------------
Method: Dijkstra's Algorithm
  Time Complexity: O(n * m * logn(n * m))
  Space Complexity: O(n * m)
-------------------------------------------*/

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {

        ios_base::sync_with_stdio(false);
        cin.tie(NULL);
        cout.tie(NULL);
        
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        pq.push({0, {0, 0}});
        dist[0][0] = 0;

        while(!pq.empty()){
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            int cost = pq.top().first;
            pq.pop();

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = i + dir.first;
                int newY = j + dir.second;

                if(newX >= 0 && newY >= 0 && newX < n && newY < m){
                    if(dist[newX][newY] > dist[i][j] + grid[newX][newY]){
                        dist[newX][newY] = dist[i][j] + grid[newX][newY];
                        pq.push({dist[newX][newY], {newX, newY}});
                    }
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-obstacle-removal-to-reach-corner/
Author: M.R.Naganathan
*/
