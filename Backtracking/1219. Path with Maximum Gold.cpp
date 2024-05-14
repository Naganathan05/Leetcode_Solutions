/*---------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(4^n)
  Space Complexity: O(n * m)
-----------------------------------------*/

class Solution {
public:
    int getMaximumGold(vector<vector<int>>& grid) {
        int maxGold = INT_MIN;
        int rows = grid.size();
        int cols = grid[0].size();
        
        for(int i = 0; i < rows; i++){
            for(int j = 0; j < cols; j++){
                if(grid[i][j]) maxGold = max(maxGold, dfs(grid, i, j));
            }
        }
        return maxGold % INT_MIN;
    }

    int dfs(vector<vector<int>> &grid, int i, int j){
        int rows = grid.size();
        int cols = grid[0].size();
        
        if(i < 0 || i >= rows || j < 0 || j >= cols || grid[i][j] == 0) 
            return 0;
        
        int temp = grid[i][j];
        grid[i][j] = 0;
        
        int gold = temp + max(dfs(grid, i - 1, j), 
                              max(dfs(grid, i + 1, j), 
                                  max(dfs(grid, i, j - 1), dfs(grid, i, j + 1))));
        grid[i][j] = temp;
        
        return gold;
    }
};

/*
Question Link: https://leetcode.com/problems/path-with-maximum-gold/
Author: M.R.Naganathan
*/
