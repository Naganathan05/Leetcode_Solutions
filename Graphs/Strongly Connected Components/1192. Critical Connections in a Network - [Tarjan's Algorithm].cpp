/*---------------------------------------
Method: Tarjan's Algorithm
  Time Complexity: O(V + E)
  Space Complexity: O(V + E) + O(3 * V)
------------------------------------------*/

class Solution {
public:
    int timer = 1;
    void DFS(vector<vector<int>> &adjList, int server, int parent, vector<int> &tin, vector<int> &low, vector<bool> &visited, vector<vector<int>> &bridges){
        visited[server] = true;
        low[server] = tin[server] = timer;
        timer += 1;
        for(int it : adjList[server]){
            if(it == parent) continue;
            if(!visited[it]){
                DFS(adjList, it, server, tin, low, visited, bridges);
                low[server] = min(low[server], low[it]);
                if(low[it] > tin[server]) bridges.push_back({server, it});
            }
            else low[server] = min(low[server], low[it]);
        }
        return;
    }

    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adjList(n);
        for(auto const& edge : connections){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> low(n);
        vector<int> tin(n);
        vector<bool> visited(n, false);
        vector<vector<int>> bridges;
        DFS(adjList, 0, -1, tin, low, visited, bridges);
        return bridges;
    }   
};

/*
Question Link: https://leetcode.com/problems/critical-connections-in-a-network/
Author: M.R.Naganathan
*/
