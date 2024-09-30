/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------*/

class Solution {
public:
    int reachableNodes(int n, vector<vector<int>>& edges, vector<int>& restricted) {
        int numNodes = edges.size() + 1;
        unordered_map<int, bool> restrictedNodes;
        for(int node : restricted) restrictedNodes[node] = true;
        vector<vector<int>> adjList(numNodes);
        for(auto const& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        int maxVisitedNodes = 0;
        vector<bool> visited(numNodes, false);
        queue<int> fifo;
        fifo.push(0);
        visited[0] = true;
        while(!fifo.empty()){
            int currNode = fifo.front();
            fifo.pop();
            maxVisitedNodes += 1;

            for(int neighbour : adjList[currNode]){
                if(visited[neighbour] || restrictedNodes.find(neighbour) != restrictedNodes.end()) continue;
                fifo.push(neighbour);
                visited[neighbour] = true;
            }
        }
        return maxVisitedNodes;
    }
};

/*
Question Link: https://leetcode.com/problems/reachable-nodes-with-restrictions/
Author: M.R.Naganathan
*/
