/*-------------------------------------
  Time Complexity: O(V + 2E)
  Space Complexity: O(3V)
----------------------------------------*/

class Solution {
  public:
    void dfs(int node, vector<int> adj[], vector<bool> &visited, vector<int> &ls){
        if(visited[node]) return;
        visited[node] = true;
        ls.push_back(node);
        for(int i : adj[node]){
            dfs(i, adj, visited, ls);
        }
    }
    
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        vector<int> ls;
        dfs(0, adj, visited, ls);
        return ls;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1
Author: M.R.Naganathan
*/
