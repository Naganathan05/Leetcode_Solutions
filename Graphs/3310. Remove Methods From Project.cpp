/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------*/

class Solution {
public:
    void DFS(vector<vector<int>> &adjList, int vertex, vector<bool> &visited, vector<int> &inDegree){
        visited[vertex] = true;
        for(int neighbour : adjList[vertex]){
            inDegree[neighbour] -= 1;
            if(!visited[neighbour]) DFS(adjList, neighbour, visited, inDegree);
        }
        return;
    }

    vector<int> remainingMethods(int n, int k, vector<vector<int>>& invocations) {
        vector<vector<int>> adjList(n);
        vector<int> inDegree(n, 0);
        for(auto invocation : invocations){
            adjList[invocation[0]].push_back(invocation[1]);
            inDegree[invocation[1]] += 1;
        }

        vector<bool> visited(n, false);
        DFS(adjList, k, visited, inDegree);
        bool canRemove = true;
        for(int i = 0; i <= n - 1; i++){
            if(visited[i]) canRemove &= (inDegree[i] == 0);
        }
        
        vector<int> nonRemovedMethods;
        if(!canRemove){
            for(int i = 0; i <= n - 1; i++) nonRemovedMethods.push_back(i);
            return nonRemovedMethods;
        }

        for(int i = 0; i <= n - 1; i++){
            if(!visited[i]) nonRemovedMethods.push_back(i);
        }
        return nonRemovedMethods;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-methods-from-project/
Author: M.R.Naganathan
*/
