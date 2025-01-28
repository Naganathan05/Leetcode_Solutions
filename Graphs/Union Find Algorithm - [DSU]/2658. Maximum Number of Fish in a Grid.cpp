/*--------------------------------
Method - Depth First Search
  Time Complexity: O(m * n)
  Space Complexity: O(max(m, n))
----------------------------------*/

class Solution {
public:
    int DFS(vector<vector<int>> &grid, int i, int j){
        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        int totalFishes = grid[i][j];
        grid[i][j] = 0; 
        for(auto &dir : directions){
            int newX = i + dir.first;
            int newY = j + dir.second;

            if(newX < 0 || newY < 0 || newX >= grid.size() || newY >= grid[0].size() || grid[newX][newY] == 0) continue;
            totalFishes += DFS(grid, newX, newY);
        }
        return totalFishes;
    }

    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();

        int maxFishes = 0;
        for(int i = 0; i <= m - 1; i++){
            for(int j = 0; j <= n - 1; j++){
                if(grid[i][j]) maxFishes = max(maxFishes, DFS(grid, i, j));
            }
        }
        return maxFishes;
    }
};

/*-------------------------------
Method - Union Find Alogorithm
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
---------------------------------*/

class DisJointSet {
public:
    vector<int> parent, size;

    DisJointSet(int totalCells) {
        parent.resize(totalCells);
        size.resize(totalCells, 0);
        for (int i = 0; i < totalCells; i++) {
            parent[i] = i;
        }
    }

    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    bool UnionBySize(int u, int v) {
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if (ult_u == ult_v) return false;

        if (size[ult_u] > size[ult_v]) {
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        } else {
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        return true;
    }
};

class Solution {
public:
    int findMaxFish(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisJointSet ds(m * n);

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] > 0) {
                    int currCell = (i * n) + j;
                    ds.size[currCell] = grid[i][j];
                }
            }
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0) continue;

                int currCell = (i * n) + j;
                for (auto& dir : directions) {
                    int newX = i + dir.first;
                    int newY = j + dir.second;

                    if (newX < 0 || newX >= m || newY < 0 || newY >= n || grid[newX][newY] == 0) continue;

                    int newCell = (newX * n) + newY;
                    ds.UnionBySize(currCell, newCell);
                }
            }
        }

        int maxFish = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                int currCell = (i * n) + j;
                int ultParent = ds.findUParent(currCell);
                maxFish = max(maxFish, ds.size[ultParent]);
            }
        }
        return maxFish;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
Author: M.R.Naganathan
*/
