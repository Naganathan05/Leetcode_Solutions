/*-----------------------------
Method: Breadth First Search
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
-------------------------------*/

class Solution {
public:
    void BFS(vector<vector<int>> &heights, queue<pair<int, int>> &fifo, vector<vector<bool>> &visited) {
        int n = heights.size();
        int m = heights[0].size();

        while(!fifo.empty()) {
            auto [currX, currY] = fifo.front();
            fifo.pop();

            vector<pair<int, int>> directions = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
            for(auto &dir : directions) {
                int newX = currX + dir.first;
                int newY = currY + dir.second;

                if(newX < 0 || newY < 0 || newX >= n || newY >= m || visited[newX][newY]) continue;
                if(heights[newX][newY] < heights[currX][currY]) continue;
                fifo.push({newX, newY});
                visited[newX][newY] = true;
            }
        }
        return;
    }

    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        vector<vector<bool>> atlanticOceanVisited(n, vector<bool> (m, false));
        vector<vector<bool>> pacificOceanVisited(n, vector<bool> (m, false));

        queue<pair<int, int>> atlanticQueue;
        queue<pair<int, int>> pacificQueue;

        for(int i = 0; i < m; i++) {
            pacificQueue.push({0, i});
            pacificOceanVisited[0][i] = true;
            atlanticQueue.push({n - 1, i});
            atlanticOceanVisited[n - 1][i] = true;
        }

        for(int i = 0; i < n; i++) {
            pacificQueue.push({i, 0});
            pacificOceanVisited[i][0] = true;
            atlanticQueue.push({i, m - 1});
            atlanticOceanVisited[i][m - 1] = true;
        }

        BFS(heights, pacificQueue, pacificOceanVisited);
        BFS(heights, atlanticQueue, atlanticOceanVisited);

        vector<vector<int>> result;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                if(!pacificOceanVisited[i][j] || !atlanticOceanVisited[i][j]) continue;
                result.push_back({i, j});
            }
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/pacific-atlantic-water-flow/
Author: M.R.Naganathan
*/
