/*-------------------------------------
Method: Union Find Algorithm - [DSU]
    Time Complexity: O(m * n)
    Space Complexity: O(m * n)
--------------------------------------*/

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
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        DisJointSet ds(m * n);

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    for(auto dir : directions) {
                        int newX = i + dir.first;
                        int newY = j + dir.second;
                        if(newX >= 0 && newX < m && newY >= 0 && newY < n && grid[newX][newY] == 1) {
                            int u = i * n + j;
                            int v = newX * n + newY;
                            ds.UnionBySize(u, v);
                        }
                    }
                }
            }
        }

        int maxIslandSize = 0;
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                if(grid[i][j] == 1) {
                    int root = ds.findUParent(i * n + j);
                    maxIslandSize = max(maxIslandSize, ds.size[root]);
                }
            }
        }
        return maxIslandSize;
    }
};

/*--------------------------------------
Method: Breadth First Search
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
----------------------------------------*/

class Solution {
public:
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool> (n, false));
        int maxIslandSize = 0;

        for(int i = 0; i <= m - 1; i++){
            for(int j = 0; j <= n - 1; j++){
                if(!visited[i][j] && grid[i][j] == 1){
                    queue<pair<int, int>> fifo;
                    fifo.push({i, j});
                    visited[i][j] = true;

                    int currIslandSize = 0;
                    while(!fifo.empty()){
                        int x = fifo.front().first;
                        int y = fifo.front().second;
                        fifo.pop();
                        currIslandSize += 1;

                        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
                        for(auto dir : directions){
                            int newX = x + dir.first;
                            int newY = y + dir.second;

                            if(newX >= 0 && newX < m && newY >= 0 && newY < n && !visited[newX][newY] && grid[newX][newY] == 1){
                                visited[newX][newY] = true;
                                fifo.push({newX, newY});
                            }
                        }
                    }
                    maxIslandSize = max(maxIslandSize, currIslandSize);
                }
            }
        }
        return maxIslandSize;
    }
};

/*
Question Link: https://leetcode.com/problems/max-area-of-island/description/
Author: M.R.Naganathan
*/
