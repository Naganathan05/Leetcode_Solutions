/*----------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(n)
  Space Complexity: O(n) + O(h)
------------------------------------*/

class Solution {
public:
    int DFS(vector<vector<int>> &adjList, int node, string &s, int &maxPathLen) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        int localMaxPathLen = 0;
        for(auto neighbour : adjList[node]) {
            int currPathLen = DFS(adjList, neighbour, s, maxPathLen);
            if(s[neighbour] == s[node]) continue;
            localMaxPathLen = max(localMaxPathLen, currPathLen);
            minHeap.push(currPathLen);
            if(minHeap.size() > 2) minHeap.pop();
        }

        int joinedPathLen = 1;
        if(minHeap.size() == 2) {
            joinedPathLen += minHeap.top();
            minHeap.pop();
            joinedPathLen += minHeap.top();
            minHeap.pop();
        }
        maxPathLen = max({maxPathLen, localMaxPathLen + 1, joinedPathLen});
        return localMaxPathLen + 1;
    }

    int longestPath(vector<int>& parent, string s) {
        int numNodes = parent.size();
        vector<vector<int>> adjList(numNodes);
        for(int node = 1; node < numNodes; node++) adjList[parent[node]].push_back(node);

        int maxPathLen = 0;
        DFS(adjList, 0, s, maxPathLen);
        return maxPathLen;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-path-with-different-adjacent-characters/
Author: M.R.Naganathan
*/
