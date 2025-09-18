/*---------------------------------------
Method: Dijkstra's Algo + Visited array
  Time Complexity: O(n * m * log(nm))
  Space Complexity: O(n * m)
-----------------------------------------*/

class Solution {
public:
    int minimumTime(vector<vector<int>>& grid) {
        if(grid[0][1] > 1 && grid[1][0] > 1) return -1;

        int n = grid.size();
        int m = grid[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        priority_queue<pair<int, pair<int, int>>,
                       vector<pair<int, pair<int, int>>>,
                       greater<pair<int, pair<int, int>>>> minHeap;

        minHeap.push({grid[0][0], {0, 0}});

        while(!minHeap.empty()) {
            auto [currTime, coords] = minHeap.top();
            auto [currX, currY] = coords;
            minHeap.pop();

            if(visited[currX][currY]) continue;
            visited[currX][currY] = true;

            if(currX == n - 1 && currY == m - 1) return currTime;

            vector<pair<int, int>> directions = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
            for(auto &dir : directions) {
                int newX = currX + dir.first;
                int newY = currY + dir.second;

                if(newX < 0 || newY < 0 || newX >= n || newY >= m || visited[newX][newY]) continue;

                int waitTime = ((grid[newX][newY] - currTime) % 2 == 0);
                int newTime = max(grid[newX][newY] + waitTime, currTime + 1);
                minHeap.push({newTime, {newX, newY}});
            }
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-time-to-visit-a-cell-in-a-grid/
Author: M.R.Naganathan
*/
