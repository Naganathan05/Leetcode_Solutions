/*--------------------------------------
Method: Union Find Algorithm - [DSU]
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
-----------------------------------------*/

class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]) {
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
    int closedIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisJointSet ds = DisJointSet(m * n);

        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                if(grid[i][j] == 0){
                    vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                    for(auto dir : directions){
                        int newX = i + dir.first;
                        int newY = j + dir.second;

                        if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 0){
                            int u = i * n + j;
                            int v = newX * n + newY;
                            ds.UnionBySize(u, v);
                        }
                    }
                }
            }
        }

        vector<bool> boundaryConnected(m * n, false);
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 0 && (i == 0 || j == 0 || i == m - 1 || j == n - 1)) {
                    int node = ds.findUParent(i * n + j);
                    boundaryConnected[node] = true;
                }
            }
        }

        int numClosedIslands = 0;
        for(int i = 1; i < m - 1; i++) {
            for(int j = 1; j < n - 1; j++) {
                if(grid[i][j] == 0) {
                    int node = ds.findUParent(i * n + j);
                    if(!boundaryConnected[node] && node == (i * n + j)) {
                        numClosedIslands++;
                    }
                }
            }
        }
        return numClosedIslands;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-closed-islands/\
Author: M.R.Naganathan
*/
