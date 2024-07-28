/*---------------------------------
Method: Dijkstra's Algorithm
  Time Complexity: O(V + ElogV)
  Space Complexity: O(V + E)
------------------------------------*/

class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        if (n == 1) return 1;
        int mod = 1e9 + 7;
        vector<vector<pair<int, int>>> adjList(n);
        for (int i = 0; i < roads.size(); i++) {
            adjList[roads[i][0]].push_back({roads[i][1], roads[i][2]});
            adjList[roads[i][1]].push_back({roads[i][0], roads[i][2]});
        }

        vector<long long> dist(n, 1e12), ways(n, 0);
        priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
        pq.push({0, 0});
        dist[0] = 0;
        ways[0] = 1;

        while (!pq.empty()) {
            int node = pq.top().second;
            long long time = pq.top().first;
            pq.pop();

            for (auto itr : adjList[node]) {
                if (dist[itr.first] > time + itr.second){
                    dist[itr.first] = time + itr.second;
                    pq.push({dist[itr.first], itr.first});
                    ways[itr.first] = ways[node] % mod;
                }
                else if (dist[itr.first] == time + itr.second){
                    ways[itr.first] = (ways[itr.first] + ways[node]) % mod;
                }
            }
        }
        return ways[n - 1];
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-ways-to-arrive-at-destination/
Author: M.R.Naganathan
*/
