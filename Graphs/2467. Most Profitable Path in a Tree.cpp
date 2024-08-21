/*----------------------------
  Time Complexity: O(V + E)
  Space Complexity: O(V + E)
-------------------------------*/

class Solution {
public:
    int mostProfitablePath(vector<vector<int>>& edges, int bob, vector<int>& amount) {
        int numNodes = edges.size() + 1;
        vector<vector<int>> adjList(numNodes);

        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        vector<int> bobVisited(numNodes, -1);
        DFS_bob(adjList, bob, -1, 0, bobVisited);
        return BFS_alice(adjList, amount, bobVisited);
    }

    bool DFS_bob(vector<vector<int>>& adjList, int node, int parent, int currTime, vector<int>& bobVisited) {
        if (node == 0) { 
            bobVisited[node] = currTime;
            return true;
        }

        bobVisited[node] = currTime;
        for (int neighbor : adjList[node]) {
            if (neighbor != parent) {
                if (DFS_bob(adjList, neighbor, node, currTime + 1, bobVisited)) {
                    return true;
                }
            }
        }
        bobVisited[node] = -1;
        return false;
    }

    int BFS_alice(vector<vector<int>>& adjList, vector<int>& amount, vector<int>& bobVisited) {
        int numNodes = adjList.size();
        queue<pair<int, pair<int, int>>> fifo;
        vector<int> maxProfit(numNodes, -1e9);

        fifo.push({amount[0], {0, 0}});
        maxProfit[0] = amount[0];

        while (!fifo.empty()) {
            int currAmount = fifo.front().first;
            int currTime = fifo.front().second.first;
            int currNode = fifo.front().second.second;
            fifo.pop();

            for (int neighbor : adjList[currNode]) {
                if (maxProfit[neighbor] == -1e9) {
                    int newAmount = currAmount;
                    if (bobVisited[neighbor] != -1) {
                        if (bobVisited[neighbor] > currTime + 1) newAmount += amount[neighbor];
                        else if (bobVisited[neighbor] == currTime + 1) newAmount += amount[neighbor] / 2;
                    } 
                    else newAmount += amount[neighbor];
                    maxProfit[neighbor] = newAmount;
                    fifo.push({newAmount, {currTime + 1, neighbor}});
                }
            }
        }

        int maxAmount = -1e9;
        for (int i = 0; i < numNodes; i++) {
            if (adjList[i].size() == 1 && i != 0) maxAmount = max(maxAmount, maxProfit[i]);
        }
        return maxAmount;
    }
};

/*
Question Link: https://leetcode.com/problems/most-profitable-path-in-a-tree/
Author: M.R.Naganathan
*/
