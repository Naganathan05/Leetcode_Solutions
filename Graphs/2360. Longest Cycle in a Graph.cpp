/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    int DFS(vector<int> &edges, int vertex, int currDist, vector<bool> &visited, unordered_map<int, int> &distMapping){
        visited[vertex] = true;
        distMapping[vertex] = currDist;
        int nextNode = edges[vertex];
        if(nextNode == -1) return -1e9;
        if(visited[nextNode]){
            if (distMapping.find(nextNode) != distMapping.end()) return currDist - distMapping[nextNode] + 1;
            else return -1;
        }
        return DFS(edges, nextNode, currDist + 1, visited, distMapping);
    }

    int longestCycle(vector<int>& edges) {
        int numNodes = edges.size();
        vector<bool> visited(numNodes, false);

        int maxCycle = 0;
        unordered_map<int, int> distMapping;
        for(int i = 0; i < numNodes; i++){
            if(!visited[i]){
                maxCycle = max(maxCycle, DFS(edges, i, 0, visited, distMapping));
                distMapping.clear();
            }
        }
        return maxCycle > 0 ? maxCycle : -1;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-cycle-in-a-graph/
Author: M.R.Naganathan
*/
