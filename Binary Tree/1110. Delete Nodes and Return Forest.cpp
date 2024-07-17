/*-------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n) + O(h)
----------------------------------*/

class Solution {
public:
    void DFS(TreeNode* root, TreeNode* parent, unordered_map<int, bool> &toDelete, vector<TreeNode*> &forestRoots){
        if(!root) return;
        if(toDelete[root -> val]){
            if(parent){
                if(parent -> left == root) parent -> left = NULL;
                if(parent -> right == root) parent -> right = NULL;
            }
            if(root -> left && !toDelete[(root -> left) -> val]) forestRoots.push_back(root -> left);
            if(root -> right && !toDelete[(root -> right) -> val]) forestRoots.push_back(root -> right);
        }
        DFS(root -> left, root, toDelete, forestRoots);
        DFS(root -> right, root, toDelete, forestRoots);
        return;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        unordered_map<int, bool> toDelete;
        for(int i : to_delete) toDelete[i] = true;

        vector<TreeNode*> forestRoots;
        if(!toDelete[root -> val]) forestRoots.push_back(root);
        DFS(root, NULL, toDelete, forestRoots);
        return forestRoots;
    }
};

/*
Question Link: https://leetcode.com/problems/delete-nodes-and-return-forest/
Author: M.R.Naganathan
*/
