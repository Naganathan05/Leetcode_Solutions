/*---------------------------------------------
  Time Complexity: O(E * logE + E * E * logv)
  Space Complexity: O(V + E)
-----------------------------------------------*/

class DisJointSet {
public:
    int numNodes;
    vector<int> parent;
    vector<long long> size;

    DisJointSet(int n) {
        parent.resize(n, -1);
        size.resize(n, 1);
        for(int i = 0; i < n; i++) parent[i] = i;
        this -> numNodes = n;
    }

    int findUParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    bool UnionBySize(int u, int v) {
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        
        if(ult_u == ult_v) return false;
        if(size[ult_u] >= size[ult_v]) {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
        else {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        }
        return true;
    }

    void clear() {
        parent.resize(numNodes, -1);
        size.resize(numNodes, 1);
        for(int i = 0; i < numNodes; i++) parent[i] = i;
    }
};

class Solution {
public:
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        DisJointSet ds = DisJointSet(n);
        vector<vector<int>> newEdges;
        for(int i = 0; i < edges.size(); i++) {
            newEdges.push_back({edges[i][0], edges[i][1], edges[i][2], i});
        }

        sort(newEdges.begin(), newEdges.end(), [&](const vector<int> &a, const vector<int> &b){
            return a[2] < b[2];
        });

        int mstCost = 0;
        ds.clear();
        for(auto &edge : newEdges) {
            if(ds.UnionBySize(edge[0], edge[1])) {
                mstCost += edge[2];
            }
        }

        vector<int> criticalEdges;
        vector<int> pseudoCriticalEdges;

        for(int i = 0; i < newEdges.size(); i++) {

            int currMSTCost = 0, cntEdges = 0;
            ds.clear();
            for(int j = 0; j < newEdges.size(); j++) {
                if(i == j) continue;
                if(ds.UnionBySize(newEdges[j][0], newEdges[j][1])) {
                    currMSTCost += newEdges[j][2];
                    cntEdges += 1;
                }
            }

            if(cntEdges < n - 1 || currMSTCost > mstCost) {
                criticalEdges.push_back(newEdges[i][3]);
                continue;
            }

            ds.clear();

            ds.UnionBySize(newEdges[i][0], newEdges[i][1]);
            currMSTCost = newEdges[i][2];
            cntEdges = 1;
            for(int j = 0; j < newEdges.size(); j++) {
                // if(i == j) continue;
                if(ds.UnionBySize(newEdges[j][0], newEdges[j][1])) {
                    currMSTCost += newEdges[j][2];
                    cntEdges += 1;
                }
            }

            if(cntEdges == n - 1 && currMSTCost == mstCost) {
                pseudoCriticalEdges.push_back(newEdges[i][3]);
            }
        }
        return {criticalEdges, pseudoCriticalEdges};
    }
};

/*
Question Link: https://leetcode.com/problems/find-critical-and-pseudo-critical-edges-in-minimum-spanning-tree/
Author: M.R.Naganathan
*/
