/*---------------------------------------
Method: Dijkstra's Algorithm
  Time Complexity: O(n * m * log(n * m))
  Space Complexity: O(n * m)
------------------------------------------*/

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();
        vector<vector<int>> dist(n, vector<int> (m, 1e9));
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq;
        dist[0][0] = 0;
        pq.push({0, {0, 0}});

        while(!pq.empty()){
            int maxDiff = pq.top().first;
            int i = pq.top().second.first;
            int j = pq.top().second.second;
            pq.pop();

            if(i == n - 1 && j == m - 1) return dist[i][j];

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = i + dir.first;
                int newY = j + dir.second;

                if(newX >= 0 && newY >= 0 && newX < n && newY < m){
                    int newMax = max(maxDiff, abs(heights[newX][newY] - heights[i][j]));
                    if(newMax < dist[newX][newY]){
                        dist[newX][newY] = newMax;
                        pq.push({newMax, {newX, newY}});
                    }
                }
            }
        }
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/path-with-minimum-effort/description/
Author: M.R.Naganathan
*/
