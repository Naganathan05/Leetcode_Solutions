/*---------------------------------------------
  Time Complexity: O(n * m * logn) + O(mlogm)
  Space Complexity: O(m)
-----------------------------------------------*/

class DisJointSet {
public:
    vector<int> size, parent;

    DisJointSet(int n) {
        size.resize(n, 1);
        parent.resize(n);
        for(int i = 0; i < n; i++) parent[i] = i;
    }

    int findUParent(int node) {
        if(parent[node] == node) return node;
        return parent[node] = findUParent(parent[node]);
    }

    void UnionBySize(int u, int v) {
        int ult_u = findUParent(u);
        int ult_v = findUParent(v);
        if(ult_u == ult_v) return;
        if(size[ult_u] < size[ult_v]) {
            parent[ult_u] = ult_v;
            size[ult_v] += size[ult_u];
        } else {
            parent[ult_v] = ult_u;
            size[ult_u] += size[ult_v];
        }
    }
};

class Solution {
public:
    bool intersect(vector<int> &a, vector<int> &b, int k) {
        int i = 0, j = 0;
        int numCommon = 0;
        while(i < a.size() && j < b.size()) {
            if (a[i] == b[j]) {
                i += 1;
                j += 1;
                numCommon += 1;
            }
            else if(a[i] > b[j]) j += 1;
            else i += 1;
        }
        return numCommon >= k;
    }

    int numberOfComponents(vector<vector<int>>& properties, int k) {
        int n = properties.size();
        int m = properties[0].size();

        for(int i = 0; i < n; i++) {
            sort(properties[i].begin(), properties[i].end());
            
            unordered_set<int> visited;
            vector<int> newArray;

            for(int j = 0; j < m; j++) {
                if(visited.find(properties[i][j]) == visited.end()) {
                    newArray.push_back(properties[i][j]);
                    visited.insert(properties[i][j]);
                }
            }
            properties[i] = newArray;
        }

        DisJointSet ds(n);

        for(int i = 0; i < n; i++) {
            for(int j = i + 1; j < n; j++) {
                if(!intersect(properties[i], properties[j], k)) continue;
                ds.UnionBySize(i, j);
            }
        }

        int numComponents = 0;
        for(int i = 0; i < n; i++) {
            if(ds.findUParent(i) == i) numComponents += 1;
        }
        return numComponents;
    }
};

/*
Question Link: https://leetcode.com/problems/properties-graph/
Author: M.R.Naganathan
*/
