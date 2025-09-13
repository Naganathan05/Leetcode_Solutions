/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class DisJointSet {
public:
    vector<int> parent, size;

    DisJointSet(int n) {
        parent.resize(n + 1, 1);
        size.resize(n + 1, 1);
        for(int i = 0; i <= n; i++) parent[i] = i;
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
            size[ult_u] += size[ult_v];
            parent[ult_v] = ult_u;
        } else {
            size[ult_v] += size[ult_u];
            parent[ult_u] = ult_v;
        }
        return true;
    }
};

class Solution {
public:
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int numAccounts = accounts.size();
        DisJointSet ds = DisJointSet(numAccounts);
        unordered_map<string, int> mapMailsInd;

        for(int i = 0; i < numAccounts; i++) {
            for(int j = 1; j < accounts[i].size(); j++) {
                string currMail = accounts[i][j];
                if(mapMailsInd.find(currMail) == mapMailsInd.end()) {
                    mapMailsInd[currMail] = i;
                }
                else ds.UnionBySize(i, mapMailsInd[currMail]);
            }
        }

        vector<vector<string>> mergedMails(numAccounts);
        for(auto i : mapMailsInd) {
            string currMail = i.first;
            int ind = ds.findUParent(i.second);
            mergedMails[ind].push_back(currMail);
        }

        vector<vector<string>> ans;
        for(int i = 0; i < numAccounts; i++) {
            if(mergedMails[i].size() == 0) continue;
            vector<string> currAccount;
            currAccount.push_back(accounts[i][0]);
            sort(mergedMails[i].begin(), mergedMails[i].end());
            for(auto mail : mergedMails[i]) currAccount.push_back(mail);
            ans.push_back(currAccount);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/accounts-merge/
Author: M.R.Naganathan
*/
