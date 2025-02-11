/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class DisjointSet {
private:
    vector<int> parent, size;
public:
    DisjointSet(int n){
        parent.resize(n);
        size.resize(n, 1);
        for (int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if (parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    bool UnionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if (ult_u == ult_v) return false;

        if (size[ult_u] > size[ult_v]){
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        } 
        else{
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        return true;
    }
};

class Solution {
public:
    int minimumHammingDistance(vector<int>& source, vector<int>& target, vector<vector<int>>& allowedSwaps) {
        DisjointSet ds(source.size());

        for (int i = 0; i < allowedSwaps.size(); i++){
            ds.UnionBySize(allowedSwaps[i][0], allowedSwaps[i][1]);
        }

        unordered_map<int, unordered_map<int, int>> components;
        for (int i = 0; i < source.size(); i++){
            int par = ds.findUParent(i);
            int val = source[i];
            components[par][val] += 1;
        }

        int hammingDistance = 0;
        for (int i = 0; i < source.size(); i++){
            int par = ds.findUParent(i);
            int val = target[i];
            if (components[par].find(val) == components[par].end() || components[par][val] == 0) hammingDistance += 1;
            else components[par][val] -= 1;
        }
        return hammingDistance;
    }
};

/*
Question Link: https://leetcode.com/problems/minimize-hamming-distance-after-swap-operations/
Author: M.R.Naganathan
*/
