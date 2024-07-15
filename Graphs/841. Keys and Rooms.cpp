/*------------------------------
  Time Complexity: O(V + E)
  Space Complexity: O(V + E)
--------------------------------*/

class Solution {
public:
    void dfs(vector<vector<int>> &adjList, int vertex, vector<bool> &visited){
        visited[vertex] = true;
        for(int i : adjList[vertex]){
            if(!visited[i]){
                dfs(adjList, i, visited);
            }
        }
    }

    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int numRooms = rooms.size();
        vector<vector<int>> adjList(numRooms);
        vector<bool> visited(numRooms, false);
        for(int i = 0; i < numRooms; i++){
            for(int j = 0; j < rooms[i].size(); j++){
                adjList[i].push_back(rooms[i][j]);
            }
        }
        dfs(adjList, 0, visited);
        for(int i = 0; i < numRooms; i++){
            if(!visited[i]) return false;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/keys-and-rooms/
Author: M.R.Naganathan
*/
