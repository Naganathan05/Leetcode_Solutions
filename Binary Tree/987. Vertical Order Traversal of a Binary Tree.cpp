/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    void DFS(TreeNode* root, int row, int col, map<int, vector<pair<int, int>>>& nodes) {
        if (!root) return;
        nodes[col].push_back({row, root->val});
        DFS(root->left, row + 1, col - 1, nodes);
        DFS(root->right, row + 1, col + 1, nodes);
    }

    vector<vector<int>> verticalTraversal(TreeNode* root) {
        map<int, vector<pair<int, int>>> nodes;
        DFS(root, 0, 0, nodes);

        vector<vector<int>> result;
        for (auto [col, pairs] : nodes) {
            sort(pairs.begin(), pairs.end());
            vector<int> colVals;
            for (auto [row, val] : pairs) colVals.push_back(val);
            result.push_back(colVals);
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/vertical-order-traversal-of-a-binary-tree/
Author: M.R.Naganathan
*/
