/*------------------------------
  Time Complexity: O(n + rlogn)
  Space Complexity: O(n + r)
--------------------------------*/

class DisJointSet {
private:
    vector<int> parent, size;
public:
    DisJointSet(int n) {
        parent.resize(n + 1, 0);
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

        if(size[ult_u] > size[ult_v]){
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        }
        else {
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        return true;
    }
};

class Solution {
public:
    vector<bool> friendRequests(int n, vector<vector<int>>& restrictions, vector<vector<int>>& requests) {
        DisJointSet ds = DisJointSet(n);
        vector<bool> requestStatus;
        for(auto &request : requests){
            DisJointSet temp = ds;
            temp.UnionBySize(request[0], request[1]);

            bool requestSuccessful = true;
            for(auto &rest : restrictions){
                if(temp.findUParent(rest[0]) == temp.findUParent(rest[1])){
                    requestSuccessful = false;
                    break;
                }
            }

            if(requestSuccessful) ds.UnionBySize(request[0], request[1]);
            requestStatus.push_back(requestSuccessful);
        }
        return requestStatus;
    }
};

/*
Question Link: https://leetcode.com/problems/process-restricted-friend-requests/
Author: M.R.Naganathan
*/
