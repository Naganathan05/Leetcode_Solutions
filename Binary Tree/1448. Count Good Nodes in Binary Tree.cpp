/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-------------------------------------------------*/

class Solution {
public:
    int recursion(TreeNode *root, int currMax){
        if(!root) return 0;

        if(root -> val >= currMax) return 1 + recursion(root -> left, root -> val) + recursion(root -> right, root -> val);
        else return recursion(root -> left, currMax) + recursion(root -> right, currMax);
    }

    int goodNodes(TreeNode* root) {
        return recursion(root, INT_MIN);
    }
};

/*
Question Link: https://leetcode.com/problems/count-good-nodes-in-binary-tree/description/
Author: M.R.Naganathan
*/
