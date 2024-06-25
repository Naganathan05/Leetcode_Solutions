/*-----------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(h)
--------------------------------*/

class Solution {
public:
    int DFS(TreeNode *root, long long targetSum){
        if(!root) return 0;

        int pick = 0;
        targetSum -= (root -> val);
        if(targetSum == 0) pick = 1;
    
        int leftPath = 0, rightPath = 0;
        leftPath = DFS(root -> left, targetSum);
        rightPath = DFS(root -> right, targetSum);
        return pick + leftPath + rightPath;
    }

    int pathSum(TreeNode* root, int targetSum) {
        if(!root) return 0;
        return DFS(root, targetSum) + pathSum(root -> left, targetSum) + pathSum(root -> right, targetSum);
    }
};

/*
Question Link: https://leetcode.com/problems/path-sum-iii/
Author: M.R.Naganathan
*/
