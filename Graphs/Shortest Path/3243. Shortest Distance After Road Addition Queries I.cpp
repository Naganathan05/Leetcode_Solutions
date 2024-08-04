/*-------------------------------------
  Time Complexity: O(q * n * n * logn)
  Space Complexity: O(n + q)
----------------------------------------*/

class Solution {
public:
    int Dijkstra(vector<vector<int>> &adjList, int n){
        vector<int> dist(n, 1e9);
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        minHeap.push({0, 0});
        dist[0] = 0;
        while(!minHeap.empty()){
            auto [currDist, node] = minHeap.top();
            minHeap.pop();

            if(node == n - 1) return dist[node];

            for(int neighbour : adjList[node]){
                if(dist[neighbour] > currDist + 1){
                    dist[neighbour] = currDist + 1;
                    minHeap.push({dist[neighbour], neighbour});
                }
            }
        }
        return n;
    }

    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        vector<vector<int>> adjList(n);
        vector<int> shortestDistance(queries.size(), n);
        for(int i = 0; i < n - 1; i++) adjList[i].push_back(i + 1);

        int i = 0;
        for(auto const& query : queries){
            adjList[query[0]].push_back(query[1]);
            shortestDistance[i] = Dijkstra(adjList, n);
            i += 1;
        }
        return shortestDistance;
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-distance-after-road-addition-queries-i/
Author: M.R.Naganathan
*/
