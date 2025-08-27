/*-----------------------------------------
  Time Complexity: O(m * n * log(m * n))
  Space Complexity: O(m * n)
-------------------------------------------*/

class Solution {
public:
    void calculateFireSpread(vector<vector<int>> &grid, vector<vector<int>> &fireSpreadTime) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>> fifo;
        for(int i = 0; i < n; i++){
            for(int j = 0; j < m; j++){
                if(grid[i][j] == 1) {
                    fifo.push({i, j});
                    fireSpreadTime[i][j] = 0;
                }
            }
        }

        int time = 0;
        while(!fifo.empty()){
            int size = fifo.size();
            time += 1;
            for(int i = 0; i < size; i++) {
                auto [currX, currY] = fifo.front();
                fifo.pop();

                vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
                for(auto &dir : directions) {
                    int newX = currX + dir.first;
                    int newY = currY + dir.second;

                    if(newX < 0 || newY < 0 || newX >= n || newY >= m || grid[newX][newY] != 0) continue;
                    if(fireSpreadTime[newX][newY] <= time) continue;
                    fireSpreadTime[newX][newY] = time;
                    fifo.push({newX, newY});
                }
            }
        }
        return;
    }

    bool validateStartTime(vector<vector<int>> &grid, int startTime, vector<vector<int>> &fireSpreadTime) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, pair<int, int>>> fifo;
        vector<vector<bool>> visited(n, vector<bool> (m, false));

        fifo.push({startTime, {0, 0}});
        visited[0][0] = true;

        while(!fifo.empty()) {
            auto [currTime, coords] = fifo.front();
            auto [currX, currY] = coords;
            fifo.pop();

            if(currX == n - 1 && currY == m - 1) return fireSpreadTime[n - 1][m - 1] >= currTime;

            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {-1, 0}, {1, 0}};
            for(auto &dir : directions) {
                int newX = currX + dir.first;
                int newY = currY + dir.second;

                if (newX < 0 || newY < 0 || newX >= n || newY >= m) continue;
                if (grid[newX][newY] == 2 || visited[newX][newY]) continue;
                if (!(newX == n - 1 && newY == m - 1) && fireSpreadTime[newX][newY] <= currTime + 1) continue;
                visited[newX][newY] = true;
                fifo.push({currTime + 1, {newX, newY}});
            }
        }
        return false;
    }

    int maximumMinutes(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> fireSpreadTime(n, vector<int> (m, 1e9));
        calculateFireSpread(grid, fireSpreadTime);

        int low = 0, high = n * m, maxStartTime = -1;
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (validateStartTime(grid, mid, fireSpreadTime)) {
                maxStartTime = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return validateStartTime(grid, 1e5, fireSpreadTime) ? 1e9 : maxStartTime;
    }
};

/*
Question Link: https://leetcode.com/problems/escape-the-spreading-fire/description/
Author: M.R.Naganathan
*/
