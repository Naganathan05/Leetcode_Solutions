/*-------------------------------------
  Time Complexity: O((V + E) * logV)
  Space Complexity: O(V + E)
---------------------------------------*/

class Solution {
public:
    vector<int> minimumTime(int n, vector<vector<int>>& edges, vector<int>& disappear) {
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap;
        vector<vector<pair<int, int>>> adjList(n);
        vector<int> dist(n, 1e9);

        for(auto edge : edges){
            adjList[edge[0]].push_back({edge[1], edge[2]});
            adjList[edge[1]].push_back({edge[0], edge[2]});
        }

        minHeap.push({0, 0});
        dist[0] = 0;
        while(!minHeap.empty()){
            auto [currDist, currNode] = minHeap.top();
            minHeap.pop();

            if (currDist > dist[currNode]) continue;

            for (auto neighbour : adjList[currNode]) {
                int nextNode = neighbour.first;
                int edgeWeight = neighbour.second;

                int newDist = dist[currNode] + edgeWeight;
                if (newDist >= disappear[nextNode]) continue;

                if (newDist < dist[nextNode]) {
                    dist[nextNode] = newDist;
                    minHeap.push({newDist, nextNode});
                }
            }
        }

        for(int i = 0; i <= n - 1; i++){
            if(dist[i] >= 1e9) dist[i] = -1;
        }
        return dist;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-time-to-visit-disappearing-nodes/
Author: M.R.Naganathan
*/
