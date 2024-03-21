/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-------------------------------------------------*/

class Solution {
public:
    int function(TreeNode *root, int currNum){
        if(!root) return 0;

        int left = 0, right = 0;
        currNum = (currNum * 10) + root -> val;
        if(root -> left == NULL && root -> right == NULL) return currNum;
        if(root -> left) left = function(root -> left, currNum);
        if(root -> right) right = function(root -> right, currNum);
        return left + right;
    }

    int sumNumbers(TreeNode* root) {
        return function(root, 0);
    }
};

/*
Question Link: https://leetcode.com/problems/sum-root-to-leaf-numbers/
Author: M.R.Naganathan
*/
