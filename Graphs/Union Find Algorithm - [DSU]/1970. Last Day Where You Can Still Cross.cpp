/*----------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
------------------------------*/

class DisJointSet {
private:
    vector<int> parent, size;
public:
    DisJointSet(int n) {
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++) parent[i] = i;
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
    int latestDayToCross(int row, int col, vector<vector<int>>& cells) {
        DisJointSet ds = DisJointSet(row * col + 2);
        vector<vector<int>> grid(row, vector<int>(col, 1));

        int start = row * col;
        int end = row * col + 1;

        vector<pair<int, int>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
        
        for (int i = cells.size() - 1; i >= 0; i--) {
            int x = cells[i][0] - 1;
            int y = cells[i][1] - 1;
            grid[x][y] = 0;
            
            int u = x * col + y; 
            if (x == 0) ds.UnionBySize(u, start);
            if (x == row - 1) ds.UnionBySize(u, end);

            for (auto& dir : directions) {
                int newX = x + dir.first;
                int newY = y + dir.second;
                if (newX >= 0 && newY >= 0 && newX < row && newY < col && grid[newX][newY] == 0) {
                    int v = newX * col + newY;
                    ds.UnionBySize(u, v);
                }
            }
            if (ds.findUParent(start) == ds.findUParent(end)) return i;
        }
        return 0;
    }
};

/*
Question Link: https://leetcode.com/problems/last-day-where-you-can-still-cross/
Author: M.R.Naganathan
*/
