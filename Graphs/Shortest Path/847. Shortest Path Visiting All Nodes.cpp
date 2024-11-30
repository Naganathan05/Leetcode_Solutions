/*----------------------------------
  Time Complexity: O(n * n * 2^n)
  Space Complexity: O(n * 2^n)
-------------------------------------*/

class Solution {
public:
    int shortestPathLength(vector<vector<int>>& graph) {
        int numNodes = graph.size();
        queue<pair<int, int>> fifo;

        int requiredMask = (1 << numNodes) - 1;
        vector<vector<bool>> visited(numNodes, vector<bool> (requiredMask + 1, false));
        for(int i = 0; i <= numNodes - 1; i++){
            fifo.push({i, (1 << i)});
            visited[i][(1 << i)] = true;
        }

        int pathLength = 0;
        while(!fifo.empty()){
            int size = fifo.size();
            for(int sz = 0; sz < size; sz++){
                auto [currNode, currMask] = fifo.front();
                fifo.pop();

                if(currMask == requiredMask) return pathLength;

                for(auto neighbour : graph[currNode]){
                    int newMask = currMask | (1 << neighbour); 
                    if(visited[neighbour][newMask]) continue;
                    fifo.push({neighbour, newMask});
                    visited[neighbour][newMask] = true;
                }
            }
            pathLength += 1;
        }
        return -1;
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-path-visiting-all-nodes/description/
Author: M.R.Naganathan
*/
