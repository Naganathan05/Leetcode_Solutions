/*------------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(V + 2E)
  Space Complexity: O(V*V)
---------------------------------------------*/

class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source, int destination) {
        vector<vector<int>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back(edges[i][1]);
            adjList[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int> visited(n, false);
        return dfs(adjList, source, destination, visited);
    }

    bool dfs(vector<vector<int>> &adjList, int source, int destination, vector<int> &visited){
        visited[source] = true;
        if(source == destination) return true;

        bool found = false;
        for(int i : adjList[source]){
            if(!visited[i]) found = found | dfs(adjList, i, destination, visited);
        }
        return found;
    }
};

/*
Question Link: https://leetcode.com/problems/find-if-path-exists-in-graph/
Author: M.R.Naganathan
*/
