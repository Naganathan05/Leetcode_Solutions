/*-----------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(m * n * k)
  Space Complexity: O(m * n * k)
-------------------------------------*/

class Solution {
public:
    int shortestPath(vector<vector<int>>& grid, int k) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<vector<bool>>> visited(n, vector<vector<bool>> (m, vector<bool> (k + 1, false)));
        queue<pair<pair<int, int>, int>> fifo;
        fifo.push({{0, 0}, k});
        visited[0][0][k] = true;
        int currSteps = 0;

        while(!fifo.empty()) {
            int size = fifo.size();
            for(int sz = 0; sz < size; sz++) {
                auto [i, j] = fifo.front().first;
                int remChances = fifo.front().second;
                fifo.pop();

                if(i == n - 1 && j == m - 1) return currSteps;

                vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                for(auto dir : directions) {
                    int newX = i + dir.first;
                    int newY = j + dir.second;

                    if(newX >= 0 && newY >= 0 && newX < n && newY < m) {
                        int newRemChances = remChances - grid[newX][newY];
                        if(newRemChances >= 0 && !visited[newX][newY][newRemChances]) {
                            fifo.push({{newX, newY}, newRemChances});
                            visited[newX][newY][newRemChances] = true;
                        }
                    }
                }
            }
            currSteps += 1;
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-path-in-a-grid-with-obstacles-elimination/
Author: M.R.Naganathan
*/
