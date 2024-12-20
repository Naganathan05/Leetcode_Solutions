/*------------------------
  Time Complexity: O(n)  
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n, 0);
        vector<int> ans;

        for(auto edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]] += 1;
        }

        for(int i = 0;  i <= n - 1; i++){
            if(inDegree[i] == 0) ans.push_back(i);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-vertices-to-reach-all-nodes/
Author: M.R.Naganathan
*/
