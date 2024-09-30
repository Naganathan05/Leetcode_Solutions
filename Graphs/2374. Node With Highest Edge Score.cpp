/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    int edgeScore(vector<int>& edges) {
        int numNodes = edges.size();
        vector<long> edgeScore(numNodes, 0);
        for(int i = 0; i <= numNodes - 1; i++) edgeScore[edges[i]] += i;

        long maxEdgeScore = 0;
        int maxEdgeNode = -1;
        for(int i = 0; i <= numNodes - 1; i++){
            if(edgeScore[i] > maxEdgeScore){
                maxEdgeScore = edgeScore[i];
                maxEdgeNode = i;
            }
            else if(edgeScore[i] == maxEdgeScore) maxEdgeNode = min(i, maxEdgeNode);
        }
        return maxEdgeNode;
    }
};

/*
Question Link: https://leetcode.com/problems/node-with-highest-edge-score/
Author: M.R.Naganathan
*/
