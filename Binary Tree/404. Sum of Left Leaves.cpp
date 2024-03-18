/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n) => Recursive Stack Space
-------------------------------------------------*/

class Solution {
public:
    int leftRecursion(TreeNode *root){
        if(!root) return 0;
        if(root -> left == NULL && root -> right == NULL){
            return root -> val;
        }
        return leftRecursion(root -> left) + rightRecursion(root -> right);
    }

    int rightRecursion(TreeNode *root){
        if(!root) return 0;
        return leftRecursion(root -> left) + rightRecursion(root -> right);
    }

    int sumOfLeftLeaves(TreeNode* root) {
        return leftRecursion(root -> left) + rightRecursion(root -> right);
    }
};

/*
Question Link: https://leetcode.com/problems/sum-of-left-leaves/
Author: M.R.Naganathan
*/
