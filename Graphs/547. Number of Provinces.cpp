/*-----------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(V) + O(V + 2E)
  Space Complexity: O(V) + O(V)
--------------------------------------------*/

class Solution {
public:
    void dfs(vector<vector<int>> &isConnected, vector<bool> &visited, int i){
        visited[i] = true;
        for(int j = 0; j <= isConnected[0].size() - 1; j++){
            if(isConnected[i][j] && !visited[j]){
                dfs(isConnected, visited, j);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int numNodes = isConnected.size();
        vector<bool> visited(numNodes, false);
        int numProvince = 0;
        for(int i = 0; i <= numNodes - 1; i++){
            if(!visited[i]){
                numProvince += 1;
                dfs(isConnected, visited, i);
            }
        }
        return numProvince;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-provinces/
Author: M.R.Naganathan
*/
