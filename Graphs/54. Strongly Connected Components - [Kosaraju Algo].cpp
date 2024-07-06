/*------------------------------
  Time Complexity: O(V + E)
  Space Complexity: O(V + E)
--------------------------------*/

class Solution {
public:
    void getSortedOrder(vector<vector<int>> &adj, int vertex, vector<bool> &visited, stack<int> &sortedOrder) {
        visited[vertex] = true;
        for (int node : adj[vertex]) {
            if (!visited[node]) {
                getSortedOrder(adj, node, visited, sortedOrder);
            }
        }
        sortedOrder.push(vertex);
    }

    void DFS(vector<vector<int>> &adjList, int vertex, vector<bool> &visited) {
        visited[vertex] = true;
        for (int node : adjList[vertex]) {
            if (!visited[node]) DFS(adjList, node, visited);
        }
        return;
    }

    int kosaraju(int V, vector<vector<int>>& adj) {
        stack<int> sortedOrder;
        vector<bool> visited(V, false);

        for (int i = 0; i < V; i++) {
            if (!visited[i]) getSortedOrder(adj, i, visited, sortedOrder);
        }

        vector<vector<int>> reversedAdj(V);
        for (int i = 0; i < adj.size(); i++) {
            for (int j = 0; j < adj[i].size(); j++) {
                reversedAdj[adj[i][j]].push_back(i);
            }
        }

        for(int i = 0; i <= V - 1; i++) visited[i] = false;

        int numSCC = 0;
        while (!sortedOrder.empty()) {
            int currVertex = sortedOrder.top();
            sortedOrder.pop();
            if (!visited[currVertex]) {
                numSCC += 1;
                DFS(reversedAdj, currVertex, visited);
            }
        }
        return numSCC;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/strongly-connected-components-kosarajus-algo/1
Author: M.R.Naganathan
*/
