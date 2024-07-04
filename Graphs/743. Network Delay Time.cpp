/*------------------------------------------
Method: Dijkstra's Shortest Path Algorithm
  Time Complexity: O(V + ElogV)
  Space Complexity: O(V + E)
---------------------------------------------*/

class Solution {
public:
    void Dijkstra(vector<vector<pair<int, int>>> &adjList, vector<int> &dist, int src){
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        dist[src] = 0;
        minHeap.push({0, src});
        while(!minHeap.empty()){
            int node = minHeap.top().second;
            int currTime = minHeap.top().first;
            minHeap.pop();
            for(auto neighbour : adjList[node]){
                int v = neighbour.first;
                int time = neighbour.second;

                if(dist[v] > time + currTime){
                    dist[v] = time + currTime;
                    minHeap.push({dist[v], v});
                }
            }
        }
        return;
    }

    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<vector<pair<int, int>>> adjList(n + 1);
        for(int i = 0; i < times.size(); i++){
            adjList[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        vector<int> dist(n + 1, 1e9);
        Dijkstra(adjList, dist, k);
        int maxTime = 0;
        for(int i = 1; i <= n; i++){
            if(dist[i] == 1e9) return -1;
            maxTime = max(maxTime, dist[i]);
        }
        return maxTime;
    }
};

/*
Question Link: https://leetcode.com/problems/network-delay-time/?envType=problem-list-v2&envId=mtxz5bd1
Author: M.R.Naganathan
*/
