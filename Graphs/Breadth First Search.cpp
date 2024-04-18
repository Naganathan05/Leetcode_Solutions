/*-------------------------------------------
  Time Complexity: O(V + 2E)
  Space Complexity: O(3V)
---------------------------------------------*/

class Solution {
  public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V, false);
        queue<int> q;
        vector<int> bfs;
        visited[0] = true;
        q.push(0);
        while(!q.empty()){
            int size = q.size();
            while(size){
                int curr = q.front();
                bfs.push_back(curr);
                q.pop();
                for(int i : adj[curr]){
                    if(!visited[i]){
                        visited[i] = true;
                        q.push(i);
                    }
                }
                size -= 1;
            }
        }
        return bfs;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/bfs-traversal-of-graph/1
Author: M.R.Naganathan
*/
