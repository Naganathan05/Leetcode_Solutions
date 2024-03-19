/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)  O(logn) => Average Case
-------------------------------------------------*/

class Solution {
public:
    int invert(TreeNode *root){
        if(!root) return 0;
        swap(root -> left, root -> right);
        invert(root -> left);
        invert(root -> right);
        return 1;
    }

    TreeNode* invertTree(TreeNode* root) {
        invert(root);
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/invert-binary-tree/description/
Author: M.R.Naganathan
*/
