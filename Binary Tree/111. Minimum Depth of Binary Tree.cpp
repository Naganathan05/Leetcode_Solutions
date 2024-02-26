/*----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-----------------------------------------------*/

class Solution {
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return 1;

        int r = INT_MAX, l = INT_MAX;
        if(root -> left) l = minDepth(root -> left);
        if(root -> right) r = minDepth(root -> right);

        return 1 + min(l, r);
    }
};

/* 
Question Link: https://leetcode.com/problems/minimum-depth-of-binary-tree/
Author: M.R.Naganathan
*/
