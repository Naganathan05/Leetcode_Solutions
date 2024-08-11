/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-----------------------------*/

class Solution {
public:
    unordered_map<int, vector<int>> adjList;
    int goodNodesCount = 0;

    int dfs(int node, int parent) {
        int size = 1;
        int expectedSize = -1;
        bool isGood = true;

        for (int child : adjList[node]) {
            if (child == parent) continue;
            int currSize = dfs(child, node);
            if (expectedSize == -1) expectedSize = currSize;
            else if (expectedSize != currSize) isGood = false;
            size += currSize;
        }
        if (isGood) goodNodesCount += 1;
        return size;
    }

    int countGoodNodes(vector<vector<int>>& edges) {
        int n = edges.size() + 1;
        adjList.clear();
        goodNodesCount = 0;

        for (const auto& edge : edges) {
            adjList[edge[0]].push_back(edge[1]);
            adjList[edge[1]].push_back(edge[0]);
        }

        dfs(0, -1);
        return goodNodesCount;
    }
};

/*
Question Link: https://leetcode.com/problems/count-the-number-of-good-nodes/
Author: M.R.Naganathan
*/
