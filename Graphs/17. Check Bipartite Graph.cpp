/*--------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(V + E)
  Space Complexity: O(V)
-----------------------------------------*/

class Solution {
public:
    bool check(int start, vector<int> adj[], vector<int> &color){
        queue<int> q;
        q.push(start);
        color[start] = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i : adj[node]){
                if(color[i] == -1){
                    color[i] = !color[node];
                    q.push(i);
                }
                else if(color[i] == color[node]){
                    return false;
                }
            }
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i = 0; i <= V - 1; i++){
	        if(color[i] == -1 && !check(i, adj, color)) return false;
	    }
	    return true;
	}
};

/*----------------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(V + 2E)
  Space Complexity: O(V)
------------------------------------------------*/

class Solution {
public:
    bool check(int node, vector<int> adj[], vector<int> &color, int lastColor){
        if(color[node] != -1 && color[node] == lastColor) return false;
        if(color[node] != -1) return true;
        color[node] = !lastColor;
        for(int i : adj[node]){
            if(!check(i, adj, color, !lastColor)) return false;
        }
        return true;
    }

	bool isBipartite(int V, vector<int>adj[]){
	    vector<int> color(V, -1);
	    for(int i = 0; i <= V - 1; i++){
	        if(color[i] == -1 && !check(i, adj, color, 0)) return false;
	    }
	    return true;
	}
};

/*
Question Link: https://www.geeksforgeeks.org/problems/bipartite-graph/1
Author: M.R.Naganathan
*/
