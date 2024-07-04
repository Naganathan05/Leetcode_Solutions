/*----------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(V + E) + O(E)
  Space Complexity: O(V)
-------------------------------------*/

class Solution {
public:
    void DFS(int vertex, vector<bool> &visited, vector<vector<int>> &adjList){
        visited[vertex] = true;
        for(int i : adjList[vertex]){
            if(!visited[i]){
                DFS(i, visited, adjList);
            }
        }
        return;
    }

    int makeConnected(int n, vector<vector<int>>& connections) {
        if(connections.size() < n - 1) return -1;
        int numComponents = 0;
        vector<vector<int>> adjList(n);
        for(int i = 0; i <= connections.size() - 1; i++){
            adjList[connections[i][0]].push_back(connections[i][1]);
            adjList[connections[i][1]].push_back(connections[i][0]);
        }
        vector<bool> visited(n, false);
        for(int i = 0; i <= n - 1; i++){
            if(!visited[i]){
                DFS(i, visited, adjList);
                numComponents += 1;
            }
        }
        return numComponents - 1;
    }
};

/*--------------------------------------------------------------
Method: Union Find Algorithm
  Time Complexity: O(V) => Initializing Parent and Size Arrays.
  Space Complexity: O(V)
----------------------------------------------------------------*/

class DisJointSet {
public:
    vector<int> parent, size;
    DisJointSet(int n){
        parent.resize(n);
        size.resize(n);
        for(int i = 0; i < n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUParent(int vertex){
        if(parent[vertex] == vertex) return vertex;
        return parent[vertex] = findUParent(parent[vertex]);
    }

    int UnionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return 1;
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        return 0;
    } 
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisJointSet ds = DisJointSet(n);
        int extraEdges = 0;
        for(int i = 0; i <= connections.size() - 1; i++){
            extraEdges += (ds.UnionBySize(connections[i][0], connections[i][1]));
        }
        int numComponents = 0;
        for(int i = 0; i <= n - 1; i++){
            if(ds.parent[i] == i) numComponents += 1;
        }
        if(numComponents - 1 > extraEdges) return -1;
        return numComponents - 1;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-operations-to-make-network-connected/
Author: M.R.Naganathan
*/
