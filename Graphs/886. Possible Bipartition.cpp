/*-------------------------------
  Time Complexity: O(V + E)
  Space Complexity: O(V + E)
----------------------------------*/

class Solution {
public:
    bool DFS(vector<vector<int>> &adjList, int vertex, int lastGroup, vector<int> &Groups, vector<bool> &visited){
        visited[vertex] = true;
        Groups[vertex] = !lastGroup;

        for(int neighbour : adjList[vertex]){
            if(visited[neighbour]){
                if(Groups[neighbour] != -1 && Groups[neighbour] == Groups[vertex]) return false;
            }
            else if(!DFS(adjList, neighbour, Groups[vertex], Groups, visited)) return false;
        }
        return true;
    }

    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        if(n <= 1) return true;
        vector<int> Groups(n + 1, -1);
        vector<bool> visited(n + 1, false);
        vector<vector<int>> adjList(n + 1);
        for(int i = 0; i <= dislikes.size() - 1; i++){
            adjList[dislikes[i][0]].push_back(dislikes[i][1]);
            adjList[dislikes[i][1]].push_back(dislikes[i][0]);
        }
        bool Possibility = true;
        for(int i = 1; i <= n; i++){
            if(!visited[i]) Possibility &= DFS(adjList, i, 0, Groups, visited);
        }
        return Possibility;
    }
};

/*
Question Link: https://leetcode.com/problems/possible-bipartition/
Author: M.R.Naganathan
*/
