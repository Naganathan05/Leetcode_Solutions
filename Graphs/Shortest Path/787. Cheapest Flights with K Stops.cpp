/*-------------------------------------------------------
Method: Breadth First Search
Scenario - Suitable for Dense Graphs with Large K Value
  Time Complexity: O(n * k)
  Space Complexity: O(n)
----------------------------------------------------------*/

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

/*-------------------------------------------------------
Method: Dijkstra's Algorithm
Scenario - Suitable for Sparse Graphs with Low K Value
  Time Complexity: O(nlogn * k)
  Space Complexity: O(n * k)
---------------------------------------------------------*/

class edgeInfo {
public:
    int node;
    int cost;
    int numStops;

    edgeInfo(int node, int cost, int numStops) {
        this -> node = node;
        this -> cost = cost;
        this -> numStops = numStops;
    }

    bool operator<(const edgeInfo &other) const {
        return cost > other.cost;
    }
};

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto &flight : flights) adjList[flight[0]].push_back({flight[1], flight[2]});

        vector<vector<int>> dist(n, vector<int>(k + 2, 1e9));
        priority_queue<edgeInfo> minHeap;

        minHeap.push(edgeInfo(src, 0, 0));
        dist[src][0] = 0;

        while (!minHeap.empty()) {
            edgeInfo currPath = minHeap.top();
            minHeap.pop();

            if (currPath.node == dst) return currPath.cost;

            if (currPath.numStops > k) continue;

            for (auto [nextNode, flightPrice] : adjList[currPath.node]) {
                int nextStopsCount = currPath.numStops + 1;
                int nextPathCost = currPath.cost + flightPrice;

                if (nextPathCost < dist[nextNode][nextStopsCount]) {
                    dist[nextNode][nextStopsCount] = nextPathCost;
                    minHeap.push(edgeInfo(nextNode, nextPathCost, nextStopsCount));
                }
            }
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/cheapest-flights-within-k-stops/
Author: M.R.Naganathan
*/
