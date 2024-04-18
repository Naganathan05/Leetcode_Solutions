/*-------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(4^n)
  Space Complexity: O(n * m)
---------------------------------------*/

class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& perimeter, vector<vector<bool>>& visited, bool &found) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || visited[i][j]) return;

        if(found && grid[i][j] == 0) return;
        
        visited[i][j] = true;

        if(grid[i][j] == 1){
            found = true;
            int currPer = 4;
            if (i - 1 >= 0 && grid[i - 1][j] == 1) currPer -= 1;
            if (j - 1 >= 0 && grid[i][j - 1] == 1) currPer -= 1;
            if (i + 1 < grid.size() && grid[i + 1][j] == 1) currPer -= 1;
            if (j + 1 < grid[0].size() && grid[i][j + 1] == 1) currPer -= 1;
            perimeter += currPer;
        }

        dfs(grid, i - 1, j, perimeter, visited, found);
        dfs(grid, i + 1, j, perimeter, visited, found); 
        dfs(grid, i, j - 1, perimeter, visited, found); 
        dfs(grid, i, j + 1, perimeter, visited, found);  
    }

    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        bool found = false;
        vector<vector<bool>> visited(grid.size(), vector<bool>(grid[0].size(), false));
        
        dfs(grid, 0, 0, perimeter, visited, found);
        
        return perimeter;
    }
};

/*
Question Link: https://leetcode.com/problems/island-perimeter/
Author: M.R.Naganathan
*/
