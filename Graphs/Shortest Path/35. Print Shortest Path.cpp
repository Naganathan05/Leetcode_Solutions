/*---------------------------------
Method: Dijkstra's Algorithm
  Time Complexity: O(ElogV)
  Space Complexity: O(V + E)
------------------------------------*/

class Solution {
public:
    vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
        vector<int> dist(n + 1, 1e9), parent(n + 1);
        
        vector<vector<pair<int, int>>> adjList(n + 1);
        for(int i = 0; i < m; i++) {
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        dist[1] = 0;
        for(int i = 1; i <= n; i++) parent[i] = i;
        pq.push({0, 1});
        
        while(!pq.empty()) {
            int u = pq.top().second;
            int we = pq.top().first;
            pq.pop();

            for(auto& itr : adjList[u]) {
                int v = itr.first;
                int weight = itr.second;
                if(dist[v] > we + weight) {
                    dist[v] = we + weight;
                    parent[v] = u;
                    pq.push({dist[v], v});
                }
            }
        }
        
        if (dist[n] == 1e9) return {-1};
        
        vector<int> path;
        int node = n;
        while (node != 1) {
            path.push_back(node);
            node = parent[node];
        }
        path.push_back(1);
        reverse(path.begin(), path.end());
        return path;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
Author: M.R.Naganathan
*/
