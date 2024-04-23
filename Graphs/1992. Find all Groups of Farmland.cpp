/*-----------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(n * n)
  Space Complexity: O(n * n)
--------------------------------------------*/

class Solution {
public:
    void dfs(vector<vector<int>> &land, int i, int j, int& maxi, int& maxj, vector<vector<bool>>& visited){
        visited[i][j] = true;
        if(i + 1 < land.size() && land[i + 1][j] == 1 && !visited[i + 1][j]) dfs(land, i + 1, j, maxi, maxj, visited);
        if(j + 1 < land[0].size() && land[i][j + 1] == 1 && !visited[i][j + 1]) dfs(land, i, j + 1, maxi, maxj, visited);
        maxi = max(maxi, i);
        maxj = max(maxj, j);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        vector<vector<int>> ans;
        vector<vector<bool>> visited(land.size(), vector<bool> (land[0].size(), false));
        for(int i = 0; i < land.size(); i++){
            for(int j = 0; j < land[0].size(); j++){
                if(land[i][j] && !visited[i][j]){
                    int maxi = i, maxj = j;
                    dfs(land, i, j, maxi, maxj, visited);
                    ans.push_back({i, j, maxi, maxj});
                }
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/find-all-groups-of-farmland/
Author: M.R.Naganathan
*/
