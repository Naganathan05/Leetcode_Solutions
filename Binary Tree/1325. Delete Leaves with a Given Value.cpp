/*------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
---------------------------------------------*/

class Solution {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root) return NULL;
        if(root -> left) root -> left = deleteLeaf(root -> left, target);
        if(root -> right) root -> right = deleteLeaf(root -> right, target);
        if(!root -> left && !root -> right && root -> val == target){
            root = NULL;
        }
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/delete-leaves-with-a-given-value/
Author: M.R.Naganathan
*/
