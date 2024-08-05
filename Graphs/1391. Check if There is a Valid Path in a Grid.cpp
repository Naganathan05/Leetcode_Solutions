/*------------------------------
  Time Complexity: O(m * n)
  Space Complexity: O(m * n)
---------------------------------*/

class Solution {
public:
    bool ValidatePath(int src, int dest, const string& direction) {
        if (src == 1) {
            if (direction == "left") return (dest == 1 || dest == 4);
            if (direction == "right") return (dest == 1 || dest == 3);
        }
        if (src == 2) {
            if (direction == "up") return (dest == 2 || dest == 3 || dest == 4);
            if (direction == "down") return (dest == 2 || dest == 5 || dest == 6);
        }
        if (src == 3) {
            if (direction == "left") return (dest == 1 || dest == 4 || dest == 6);
            if (direction == "down") return (dest == 2 || dest == 5 || dest == 6);
        }
        if (src == 4) {
            if (direction == "right") return (dest == 1 || dest == 3 || dest == 5);
            if (direction == "down") return (dest == 2 || dest == 5 || dest == 6);
        }
        if (src == 5) {
            if (direction == "left") return (dest == 1 || dest == 4 || dest == 6);
            if (direction == "up") return (dest == 2 || dest == 3 || dest == 4);
        }
        if (src == 6) {
            if (direction == "right") return (dest == 1 || dest == 3 || dest == 5);
            if (direction == "up") return (dest == 2 || dest == 3 || dest == 4);
        }
        return false;
    }

    bool hasValidPath(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        queue<pair<int, int>> q;

        vector<vector<int>> directions = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};
        
        q.push({0, 0});
        visited[0][0] = true;
        
        while (!q.empty()) {
            int x = q.front().first;
            int y = q.front().second;
            q.pop();
            
            if (x == m - 1 && y == n - 1) return true;
            
            for (auto& dir : directions) {
                int nx = x + dir[0];
                int ny = y + dir[1];
                
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && !visited[nx][ny]) {
                    int currentStreet = grid[x][y];
                    int nextStreet = grid[nx][ny];
                    
                    string dirStr;
                    if (dir[0] == 0 && dir[1] == -1) dirStr = "left";
                    if (dir[0] == 0 && dir[1] == 1) dirStr = "right";
                    if (dir[0] == -1 && dir[1] == 0) dirStr = "up";
                    if (dir[0] == 1 && dir[1] == 0) dirStr = "down";
                    
                    if (ValidatePath(currentStreet, nextStreet, dirStr)) {
                        q.push({nx, ny});
                        visited[nx][ny] = true;
                    }
                }
            }
        }
        return false;
    }
};

/*
Question Link: https://leetcode.com/problems/check-if-there-is-a-valid-path-in-a-grid/
Author: M.R.Naganathan
*/
