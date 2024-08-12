/*-----------------------------
  Time Complexity: O(V * E)
  Space Complexity: O(V * V)
--------------------------------*/

class Solution {
public:
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n, 0);
        for(auto const& edge : edges){
            adjList[edge[0]].push_back(edge[1]);
            inDegree[edge[1]] += 1;
        }

        vector<set<int>> ancestors(n);
        queue<int> fifo;
        for(int i = 0; i <= n - 1; i++){
            if(inDegree[i] == 0) fifo.push(i);
        }

        while(!fifo.empty()){
            int node = fifo.front();
            fifo.pop();

            for(int neighbour : adjList[node]){
                ancestors[neighbour].insert(node);
                ancestors[neighbour].insert(ancestors[node].begin(), ancestors[node].end());
                inDegree[neighbour] -= 1;
                if(inDegree[neighbour] == 0) fifo.push(neighbour);
            }
        }

        vector<vector<int>> ans;
        for(int i = 0; i <= n - 1; i++){
            vector<int> currList;
            for(auto itr = ancestors[i].begin(); itr != ancestors[i].end(); itr++) currList.push_back(*itr);
            ans.push_back(currList);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/all-ancestors-of-a-node-in-a-directed-acyclic-graph/
Author: M.R.Naganathan
*/
