/*---------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
------------------------------------*/

class Solution {
public:
    int getSum(TreeNode* root){
        if(!root) return 0;
        return root -> val + getSum(root -> left) + getSum(root -> right);
    }

    void convert(TreeNode* root, int &currSum, int totSum){
        if(!root) return;
        convert(root -> left, currSum, totSum);
        int temp = root -> val;
        root-> val = (totSum - currSum);
        currSum += (temp);
        convert(root -> right, currSum, totSum);
        return;
    }

    TreeNode* bstToGst(TreeNode* root) {
        int sum = getSum(root);
        int currSum = 0;
        convert(root, currSum, sum);
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
Author: M.R.Naganathan
*/
