/*-----------------------------
  Time Complexity: O(E * logn)
  Space Complexity: O(n)
--------------------------------*/

class DisJointSet {
public:
    vector<int> parent, size;

    DisJointSet(int n){
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    bool UnionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return false;
        if(size[ult_u] >= size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        return true;
    }
};

class Solution {
public:
    bool traverseCheck(DisJointSet& ds, int n){
        int numComponents = 0;
        for(int i = 1; i <= n; i++) numComponents += (ds.findUParent(i) == i);
        return numComponents == 1;
    }

    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisJointSet Alice = DisJointSet(n);
        DisJointSet Bob = DisJointSet(n);
        int minEdges = 0;

        for(auto const& edge : edges){
            int type = edge[0], src = edge[1], dst = edge[2];
            if(type != 3) continue;
            if(Alice.UnionBySize(src, dst) | Bob.UnionBySize(src, dst)) minEdges += 1;
        }

        for(auto const& edge : edges){
            int type = edge[0], src = edge[1], dst = edge[2];
            if(type == 1){
                if(Alice.UnionBySize(src, dst)) minEdges += 1;
            }
            else if(type == 2){
                if(Bob.UnionBySize(src, dst)) minEdges += 1;
            }
        }
        if(!traverseCheck(Alice, n) || !traverseCheck(Bob, n)) return -1;
        return edges.size() - minEdges;
    }
};

/*
Question Link: https://leetcode.com/problems/remove-max-number-of-edges-to-keep-graph-fully-traversable/
Author: M.R.Naganathan
*/
