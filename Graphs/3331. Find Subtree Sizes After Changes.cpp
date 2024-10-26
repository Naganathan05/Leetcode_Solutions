/*----------------------------
  Time Complexity: O(V)
  Space Complexity: O(V + E)
-------------------------------*/

class Solution {
public:
    void DFS(vector<vector<int>> &adjList, int node, unordered_map<char, int> &charMapping, string &s, vector<int> &newParent) {
        if (charMapping[s[node]] != -1) {
            int closestAncestor = charMapping[s[node]];
            newParent[node] = closestAncestor;
        }

        int previous = charMapping[s[node]];
        charMapping[s[node]] = node;

        for (int child : adjList[node]) DFS(adjList, child, charMapping, s, newParent);
        charMapping[s[node]] = previous;
        return;
    }

    int calculateSubtreeSize(vector<vector<int>> &finalAdjList, int node, vector<int> &answer) {
        int subtreeSize = 1;

        for (int child : finalAdjList[node]) subtreeSize += calculateSubtreeSize(finalAdjList, child, answer);
        answer[node] = subtreeSize;
        return subtreeSize;
    }

    vector<int> findSubtreeSizes(vector<int>& parent, string s) {
        int n = parent.size();
        vector<vector<int>> adjList(n);
        for (int i = 1; i < n; i++) adjList[parent[i]].push_back(i);

        unordered_map<char, int> charMapping;
        for (char letter = 'a'; letter <= 'z'; letter++) charMapping[letter] = -1;

        vector<int> newParent = parent;
        DFS(adjList, 0, charMapping, s, newParent);

        vector<vector<int>> finalAdjList(n);
        for (int i = 1; i < n; i++) {
            if (newParent[i] != -1) finalAdjList[newParent[i]].push_back(i);
        }

        vector<int> answer(n, 0);
        calculateSubtreeSize(finalAdjList, 0, answer);
        return answer;
    }
};

/*
Question Link: https://leetcode.com/problems/find-subtree-sizes-after-changes/
Author: M.R.Naganathan
*/
