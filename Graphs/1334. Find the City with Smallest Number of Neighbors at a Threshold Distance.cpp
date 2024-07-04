/*-----------------------------------
  Time Complexity: O(n * (V + ElogV))
  Space Complexity: O(n + E)
--------------------------------------*/

class Solution {
public:
    void Dijkstra(vector<vector<pair<int, int>>> &adjList, int src, vector<int> &dist){
        dist[src] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, src});
        while(!minHeap.empty()){
            int u = minHeap.top().second;
            int w = minHeap.top().first;
            minHeap.pop();
            for(auto neighbour : adjList[u]){
                int v = neighbour.first;
                int time = neighbour.second;

                if(dist[v] > time + w){
                    dist[v] = time + w;
                    minHeap.push({dist[v], v});
                }
            }
        }
    }

    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<pair<int, int>>> adjList(n);
        for(int i = 0; i < edges.size(); i++){
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adjList[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        
        int minCity = -1, minNodeCities = INT_MAX;   
        for(int i = 0; i < n; i++){
            int numCities = 0;
            vector<int> dist(n, INT_MAX);
            Dijkstra(adjList, i, dist);
            for(int node = 0; node < n; node++){
                if(dist[node] <= distanceThreshold) numCities += 1;
            }
            if(numCities <= minNodeCities){
                minNodeCities = numCities;
                minCity = i;
            }
        }
        return minCity;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-city-with-the-smallest-number-of-neighbors-at-a-threshold-distance/
Author: M.R.Naganathan
*/
