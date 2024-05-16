/*----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
------------------------------------*/

class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if(root -> val == 0 || root -> val == 1) return root -> val;
        bool left = evaluateTree(root -> left);
        bool right = evaluateTree(root -> right);
        return calculate(root -> val, left, right);
    }

    bool calculate(int val, bool left, bool right){
        if(val == 2) return left || right;
        return left && right;
    }
};

/*
Question Link: https://leetcode.com/problems/evaluate-boolean-binary-tree/
Author: M.R.Naganathan
*/
