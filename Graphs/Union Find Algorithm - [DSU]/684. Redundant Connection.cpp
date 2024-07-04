/*-------------------------------
  Time Complexity: O(V + E)
  Space Complexity: O(V)
---------------------------------*/

class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n){
        size.resize(n + 1, 1);
        parent.resize(n + 1);
        for(int i = 1; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]){
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        else{
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        return;
    }
};

class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        DisJointSet ds = DisJointSet(n);

        vector<int> redundantEdge(2, -1);
        for(int i = 0; i <= edges.size() - 1; i++){
            int u = edges[i][0];
            int v = edges[i][1];

            int ult_u = ds.findUParent(u);
            int ult_v = ds.findUParent(v);
            if(ult_u == ult_v){
                redundantEdge[0] = u;
                redundantEdge[1] = v;
            }
            else{
                ds.UnionBySize(u, v);
            }
        }
        return redundantEdge;
    }
};

/*
Question Link: https://leetcode.com/problems/redundant-connection/
Author: M.R.Naganathan
*/
