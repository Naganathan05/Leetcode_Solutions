/*-------------------------------
  Time Complexity: O(n + m)
  Space Complexity: O(n + m)
---------------------------------*/

class Solution {
  public:
    void DFS(vector<vector<pair<int, int>>> &adjList, int vertex, vector<bool> &visited, stack<int> &st){
        visited[vertex] = true;
        for(auto i : adjList[vertex]){
            if(!visited[i.first]){
                DFS(adjList, i.first, visited, st);
            }
        }
        st.push(vertex);
    }
  
     vector<int> shortestPath(int N,int M, vector<vector<int>>& edges){
        vector<vector<pair<int, int>>> adjList(N);
        for(int i = 0; i < M; i++){
            adjList[edges[i][0]].push_back({edges[i][1], edges[i][2]});
        }
        
        vector<int> dist(N, 1e9);
        stack<int> st;
        vector<bool> visited(N, false);
        
        for(int i = 0; i < N; i++){
            if(!visited[i]){
                DFS(adjList, i, visited, st);
            }
        }
        
        dist[0] = 0;
        while(!st.empty()){
            int node = st.top();
            st.pop();
            
            for(auto i : adjList[node]){
                int v = i.first;
                int we = i.second;
                
                dist[v] = min(dist[v], dist[node] + we);
            }
        }
        
        for(int i = 0; i < N; i++){
            if(dist[i] == 1e9) dist[i] = -1; 
        }
        return dist;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/shortest-path-in-undirected-graph/0
Author: M.R.Naganathan
*/
