/*-------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
----------------------------------------*/

class Solution {
public:
    TreeNode* Common(TreeNode* root, TreeNode* p, TreeNode* q){
        if(!root) return NULL;
        if((root -> val <= p -> val && root -> val >= q -> val) || (root -> val >= p -> val && root -> val <= q -> val)) return root;
        if(root -> val < p -> val && root -> val < q -> val) return Common(root -> right, p, q);
        if(root -> val > p -> val && root -> val > p -> val) return Common(root -> left, p, q);
        return NULL;
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        return Common(root, p, q);
    }
};

/*
Question Link: https://leetcode.com/problems/lowest-common-ancestor-of-a-binary-search-tree/
Author: M.R.Naganathan
*/
