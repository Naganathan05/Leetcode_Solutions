/*------------------------------------------------
  Time Complexity: O(m * n * (m * n * log(m * n)))
  Space Complexity: O(m * n)
---------------------------------------------------*/

class Solution {
public:
    bool findSafeWalk(vector<vector<int>>& grid, int health) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>> dist(n, vector<int> (m, -1e9));
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        dist[0][0] = health - grid[0][0];
        maxHeap.push({health - grid[0][0], {0, 0}});

        while(!maxHeap.empty()){
            int currHealth = maxHeap.top().first;
            int i = maxHeap.top().second.first;
            int j = maxHeap.top().second.second;
            maxHeap.pop();

            if(i == n - 1 && j == m - 1 && currHealth >= 1) return true;

            vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
            for(auto dir : directions){
                int newX = i + dir.first;
                int newY = j + dir.second;

                if(newX < 0 || newY < 0 || newX >= n || newY >= m) continue;
                int remHealth = currHealth - grid[newX][newY];
                if(dist[newX][newY] < remHealth){
                    dist[newX][newY] = remHealth;
                    maxHeap.push({remHealth, {newX, newY}});
                }
            }
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/find-a-safe-walk-through-a-grid/
Author: M.R.Naganathan
*/
