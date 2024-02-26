/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-----------------------------------------------*/

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return 1;

        int r = INT_MIN, l = INT_MIN;
        if(root -> left) l = maxDepth(root -> left);
        if(root -> right) r = maxDepth(root -> right);

        return 1 + max(l, r);
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-depth-of-binary-tree/description/
Author: M.R.Naganathan
*/
