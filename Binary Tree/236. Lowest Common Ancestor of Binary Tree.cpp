/*-----------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-------------------------------------------*/

class Solution {
public:
    TreeNode* dfs(TreeNode *root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;

        if(root == p || root == q) return root;

        TreeNode* leftSearch = dfs(root -> left, p, q);
        TreeNode* rightSearch = dfs(root -> right, p, q);
        if(leftSearch && rightSearch) return root;
        if(!leftSearch && rightSearch) return rightSearch;
        if(leftSearch && !rightSearch) return leftSearch;
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return dfs(root, p, q);
    }
};

/*
Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-tree/
Author: M.R.Naganathan
*/
