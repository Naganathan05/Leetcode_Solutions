/*----------------------------
  Time Complexity: O(V)
  Space Complexity: O(V + E)
-------------------------------*/

class Solution {
public:
    int minReorder(int n, vector<vector<int>>& connections) {
        vector<vector<pair<int, int>>> adjList(n);
        for (auto const& connection : connections) {
            adjList[connection[0]].push_back({connection[1], 1});
            adjList[connection[1]].push_back({connection[0], 0});
        }

        vector<bool> visited(n, false);
        queue<int> fifo;
        fifo.push(0);
        visited[0] = true;
        int roadsReversed = 0;

        while (!fifo.empty()) {
            int node = fifo.front();
            fifo.pop();

            for (auto& neighbor : adjList[node]) {
                int nextNode = neighbor.first;
                int needsReversing = neighbor.second;
                if (!visited[nextNode]) {
                    visited[nextNode] = true;
                    roadsReversed += needsReversing;
                    fifo.push(nextNode);
                }
            }
        }
        return roadsReversed;
    }
};

/*
Question Link: https://leetcode.com/problems/sort-items-by-groups-respecting-dependencies/description/
Author: M.R.Naganathan
*/
