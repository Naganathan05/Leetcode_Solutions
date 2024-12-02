/*--------------------------------
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

/*
Question Link: https://leetcode.com/problems/maximum-number-of-fish-in-a-grid/
Author: M.R.Naganathan
*/
