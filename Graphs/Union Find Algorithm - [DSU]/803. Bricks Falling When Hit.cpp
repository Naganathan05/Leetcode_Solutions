/*----------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------*/

class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for (int i = 0; i < n; i++) parent[i] = i;
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
    vector<int> hitBricks(vector<vector<int>>& grid, vector<vector<int>>& hits) {
        int rows = grid.size();
        int col = grid[0].size();

        DisJointSet ds = DisJointSet(rows * col + 1);
        for (auto hit : hits) {
            if (grid[hit[0]][hit[1]] == 1) grid[hit[0]][hit[1]] = -1;
        }

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        for (int i = 0; i < rows; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] != 1) continue;
                int u = i * col + j + 1;
                for (auto dir : directions) {
                    int newX = i + dir.first;
                    int newY = j + dir.second;

                    if (newX < 0 || newY < 0 || newX >= rows || newY >= col || grid[newX][newY] != 1) continue;
                    int v = newX * col + newY + 1;
                    ds.UnionBySize(u, v);
                }
                if (i == 0) ds.UnionBySize(0, u);
            }
        }

        int leftBricks = ds.size[ds.findUParent(0)];
        vector<int> result(hits.size());

        for (int i = hits.size() - 1; i >= 0; i--) {
            int currX = hits[i][0];
            int currY = hits[i][1];
            if (grid[currX][currY] == -1) {
                grid[currX][currY] = 1;
                int u = currX * col + currY + 1;
                for (auto dir : directions) {
                    int newX = currX + dir.first;
                    int newY = currY + dir.second;

                    if (newX < 0 || newY < 0 || newX >= rows || newY >= col || grid[newX][newY] != 1) continue;
                    int v = newX * col + newY + 1;
                    ds.UnionBySize(u, v);
                }
                if (currX == 0) ds.UnionBySize(0, u);
                int newBricks = ds.size[ds.findUParent(0)];
                result[i] = max(newBricks - leftBricks - 1, 0);
                leftBricks = newBricks;
            }
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/bricks-falling-when-hit/
Author: M.R.Naganathan
*/
