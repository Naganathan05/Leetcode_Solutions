/*--------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------------*/

class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n) {
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if (ult_u == ult_v) return;
        if (size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        if (n == 0) return 0;
        int m = grid[0].size();
        DisJointSet ds(n * m);

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    for (auto dir : directions) {
                        int newX = i + dir.first;
                        int newY = j + dir.second;

                        if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                            int u = i * m + j;
                            int v = newX * m + newY;
                            ds.UnionBySize(u, v);
                        }
                    }
                }
            }
        }

        unordered_map<int, int> islandSize;
        int maxIslandSize = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 1) {
                    int parent = ds.findUParent(i * m + j);
                    islandSize[parent] = ds.size[parent];
                    maxIslandSize = max(maxIslandSize, ds.size[parent]);
                }
            }
        }

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid[i][j] == 0) {
                    unordered_map<int, int> uniqueIslands;
                    int currentSize = 1;
                    for (auto dir : directions) {
                        int newX = i + dir.first;
                        int newY = j + dir.second;

                        if (newX >= 0 && newX < n && newY >= 0 && newY < m && grid[newX][newY] == 1) {
                            int parent = ds.findUParent(newX * m + newY);
                            if (uniqueIslands.find(parent) == uniqueIslands.end()) {
                                uniqueIslands[parent] = ds.size[parent];
                                currentSize += ds.size[parent];
                            }
                        }
                    }
                    maxIslandSize = max(maxIslandSize, currentSize);
                }
            }
        }
        
        return maxIslandSize;
    }
};

/*
Question Link: https://leetcode.com/problems/making-a-large-island/
Author: M.R.Naganathan
*/
