/*-------------------------------------------------
Method: Breadth First Search - [BFS]
    Time Complexity: O(n * n * m) + O(n * mlogm)
    Space Complexity: O(n * m)
  n -> Number of Bus(Routes), m -> Number of Stops
---------------------------------------------------*/

class Solution {
public:
    bool hasCommonStop(vector<int> &firstRoute, vector<int> &secondRoute) {
        int i = 0, j = 0;
        while(i < firstRoute.size() && j < secondRoute.size()) {
            if(firstRoute[i] == secondRoute[j]) return true;
            if(firstRoute[i] >= secondRoute[j]) j += 1;
            else i += 1;
        }
        return false;
    }

    bool routeHasStop(vector<int> &route, int stop) {
        for(int i = 0; i < route.size(); i++) {
            if(stop == route[i]) return true;
        }
        return false;
    }

    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        int numBus = routes.size();
        vector<vector<int>> adjList(numBus);

        for(auto &route : routes) sort(route.begin(), route.end());
        
        for(int i = 0; i < numBus; i++) {
            for(int j = i + 1; j < numBus; j++) {
                if(!hasCommonStop(routes[i], routes[j])) continue;
                adjList[i].push_back(j);
                adjList[j].push_back(i);
            }
        }

        queue<int> fifo;
        unordered_set<int> visitedBus;
        for(int i = 0; i < numBus; i++) {
            if(routeHasStop(routes[i], source)) {
                visitedBus.insert(i);
                fifo.push(i);
            }
        }

        int numBusHops = 1;
        while(!fifo.empty()) {
            int levelSize = fifo.size();
            for(int sz = 0; sz < levelSize; sz++) {
                auto currBus = fifo.front();
                fifo.pop();

                if(routeHasStop(routes[currBus], target)) {
                    return numBusHops;
                }

                for(auto &neighbourBus : adjList[currBus]) {
                    if(visitedBus.find(neighbourBus) != visitedBus.end()) continue;
                    fifo.push(neighbourBus);
                    visitedBus.insert(neighbourBus);
                }
            }
            numBusHops += 1;
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/bus-routes/
Author: M.R.Naganathan
*/
