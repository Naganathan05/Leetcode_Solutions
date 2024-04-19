/*---------------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(m * n)
  Space Complexity: O(m * n) + O(max(m, n))
------------------------------------------------*/

class Solution {
public:
    void dfs(vector<vector<char>> &grid, int i, int j, vector<vector<bool>> &visited){
        visited[i][j] = true;
        if(i + 1 < grid.size() && grid[i + 1][j] == '1' && !visited[i + 1][j]) dfs(grid, i + 1, j, visited);
        if(j + 1 < grid[0].size() && grid[i][j + 1] == '1' && !visited[i][j + 1]) dfs(grid, i, j + 1, visited);
        if(i - 1 >= 0 && grid[i - 1][j] == '1' && !visited[i - 1][j]) dfs(grid, i - 1, j, visited);
        if(j - 1 >= 0 && grid[i][j - 1] == '1' && !visited[i][j - 1]) dfs(grid, i, j - 1, visited);
    }

    int numIslands(vector<vector<char>>& grid) {
        int numIsland = 0;
        vector<vector<bool>> visited(grid.size(), vector<bool> (grid[0].size(), false));
        for(int i = 0; i <= grid.size() - 1; i++){
            for(int j = 0; j <= grid[0].size() - 1; j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    numIsland += 1;
                    dfs(grid, i, j, visited);
                }
            }
        }
        return numIsland;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-islands/
Author: M.R.Naganathan
*/
