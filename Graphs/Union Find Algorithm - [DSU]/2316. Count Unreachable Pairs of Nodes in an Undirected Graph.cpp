/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class DisJointSet {
private:
    vector<int> parent;
    vector<int> size;
public:
    DisJointSet(int n) {
        parent.resize(n + 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
    }

    int findUParent(int node){
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v){
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;

        if(size[ult_u] >= size[ult_v]){
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else{
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        return;
    }

    int getSize(int u){
        return size[u];
    }
};

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        DisJointSet* dsu = new DisJointSet(n);
        for(auto const& edge : edges) dsu -> UnionBySize(edge[0], edge[1]);

        vector<int> componentSizes;
        for(int i = 0; i <= n - 1; i++){
            if(dsu -> findUParent(i) == i) componentSizes.push_back(dsu -> getSize(i));
        }

        long long numComponents = componentSizes.size();
        long long numUnreachableNodes = 0, currComponentSize = 0;
        for(int i = 0; i <= numComponents - 1; i++){
            // cout << componentSizes[i] << endl;
            currComponentSize += componentSizes[i];
            numUnreachableNodes += (componentSizes[i] * (n - currComponentSize));
        }
        return numUnreachableNodes;
    }
};

/*
Question Link: https://leetcode.com/problems/count-unreachable-pairs-of-nodes-in-an-undirected-graph/
Author: M.R.Naganathan
*/
