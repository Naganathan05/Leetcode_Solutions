/*----------------------------
Method: Breadth First Search
  Time Complexity: O(V + 2E)
  Space Complexity: O(V + E)
-------------------------------*/

class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<vector<pair<int, int>>> adjList(n);
        
        for(auto const& edge : redEdges) adjList[edge[0]].push_back({edge[1], 0});
        for(auto const& edge : blueEdges) adjList[edge[0]].push_back({edge[1], 1});
        
        vector<int> dist(n, -1);
        vector<vector<bool>> visited(n, vector<bool>(2, false));
        
        queue<pair<int, int>> fifo;
        fifo.push({0, 0}); 
        fifo.push({0, 1});
        dist[0] = 0;
        int steps = 0;
        
        while(!fifo.empty()){
            int size = fifo.size();
            steps += 1;
            
            for(int i = 0; i < size; i++){
                auto [node, lastColor] = fifo.front();
                fifo.pop();

                for(auto [neighbor, edgeColor] : adjList[node]){
                    if(edgeColor != lastColor && !visited[neighbor][edgeColor]){
                        visited[neighbor][edgeColor] = true;
                        fifo.push({neighbor, edgeColor});
                        if(dist[neighbor] == -1) dist[neighbor] = steps;
                    }
                }
            }
        } 
        return dist;
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-path-with-alternating-colors/
Author: M.R.Naganathan
*/
