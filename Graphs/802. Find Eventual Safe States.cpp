/*-----------------------------
Time Complexity: O(n)
Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    bool SafeNodes(vector<vector<int>> &graph, int vertex, vector<int> &state, vector<bool> &safeNodes) {
        if (state[vertex] != 0) {
            return state[vertex] == 2;
        }

        state[vertex] = 1;
        for (int i : graph[vertex]) {
            if (state[i] == 2) continue;
            if (state[i] == 1 || !SafeNodes(graph, i, state, safeNodes)) {
                return false;
            }
        }
        state[vertex] = 2;
        safeNodes[vertex] = true;
        return true;
    }

    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<bool> safeNodes(n, false);
        vector<int> state(n, 0);
        vector<int> ans;

        for (int i = 0; i < n; i++) {
            if (state[i] == 0) SafeNodes(graph, i, state, safeNodes);
        }
        for (int i = 0; i < n; i++) {
            if (safeNodes[i]) ans.push_back(i);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/find-eventual-safe-states/
Author: M.R.Naganathan
*/
