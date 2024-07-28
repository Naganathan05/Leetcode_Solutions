/*---------------------------------
Method: Breadth First Search
  Time Complexity: O(n * m)
  Space Complexity: O(n * m)
-----------------------------------*/

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<int> dist(n, 1e9);
        dist[src] = 0;
        
        queue<pair<int, pair<int, int>>> fifo;
        fifo.push({0, {0, src}});
        
        vector<vector<pair<int, int>>> adjList(n);
        for (const auto& flight : flights) {
            adjList[flight[0]].push_back({flight[1], flight[2]});
        }

        while (!fifo.empty()) {
            auto [cost, state] = fifo.front();
            auto [stops, node] = state;
            fifo.pop();

            if (stops > k) continue;

            for (auto neighbor : adjList[node]) {
                int nextNode = neighbor.first;
                int price = neighbor.second;

                if (cost + price < dist[nextNode]) {
                    dist[nextNode] = cost + price;
                    fifo.push({cost + price, {stops + 1, nextNode}});
                }
            }
        }
        return dist[dst] == 1e9 ? -1 : dist[dst];
    }
};

/*
Question Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
Author: M.R.Naganathan
*/
