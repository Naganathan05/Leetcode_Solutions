/*-------------------------------------
  Time Complexity: O(V * V * maxTime)
  Space Complexty: O(V * maxTime)
----------------------------------------*/

class Solution {
public:
    int Cost(int maxTime, vector<vector<pair<int, int>>> &adjList, vector<int> &passingFees, int currCity, int currTime, vector<vector<int>> &dp) {
        if (currCity == passingFees.size() - 1) return passingFees[currCity];
        if (currTime > maxTime) return 1e9;
        if (dp[currCity][currTime] != -1) return dp[currCity][currTime];

        int minCost = 1e9;
        for (auto &[nextCity, travelTime] : adjList[currCity]) {
            if (currTime + travelTime <= maxTime) {
                minCost = min(minCost, passingFees[currCity] + Cost(maxTime, adjList, passingFees, nextCity, currTime + travelTime, dp));
            }
        }
        return dp[currCity][currTime] = minCost;
    }

    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int numCities = passingFees.size();
        vector<vector<int>> dp(numCities, vector<int>(maxTime + 1, -1));
        vector<vector<pair<int, int>>> adjList(numCities);
        
        for (const auto& edge : edges) {
            adjList[edge[0]].emplace_back(edge[1], edge[2]);
            adjList[edge[1]].emplace_back(edge[0], edge[2]);
        }
        
        int minCost = Cost(maxTime, adjList, passingFees, 0, 0, dp);
        return (minCost >= 1e9) ? -1 : minCost;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-cost-to-reach-destination-in-time/
Author: M.R.Naganathan
*/
