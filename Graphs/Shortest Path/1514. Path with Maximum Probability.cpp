/*-------------------------------
Method: Dijkstra's Algorithm
  Time Complexity: O(V + ElogV)
  Space Complexity: O(V + E)
---------------------------------*/

class Solution {
public:
    double maxProbability(int n, vector<vector<int>>& edges, vector<double>& succProb, int start_node, int end_node) {
        vector<vector<pair<int, double>>> adjList(n);
        for(int i = 0; i <= edges.size() - 1; i++){
            adjList[edges[i][0]].push_back({edges[i][1], succProb[i]});
            adjList[edges[i][1]].push_back({edges[i][0], succProb[i]});
        }

        vector<double> dist(n, 0);
        priority_queue<pair<double, int>> pq;
        pq.push({1.0, start_node});
        dist[start_node] = 1.0;

        while(!pq.empty()){
            int node = pq.top().second;
            double prob = pq.top().first;
            pq.pop();

            if(node == end_node) return prob;

            for(auto itr : adjList[node]){
                if(dist[itr.first] < prob * itr.second){
                    dist[itr.first] = prob * itr.second;
                    pq.push({dist[itr.first], itr.first});
                }
            }
        }
        return 0.0;
    }
};

/*
Question Link: https://leetcode.com/problems/path-with-maximum-probability/
Author: M.R.Naganathan
*/
