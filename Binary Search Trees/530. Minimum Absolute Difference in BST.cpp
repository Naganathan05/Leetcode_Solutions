/*---------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------*/

class Solution {
public:
    void getInorder(TreeNode* root, vector<int> &inorder){
        if(!root) return;
        getInorder(root -> left, inorder);
        inorder.push_back(root -> val);
        getInorder(root -> right, inorder);
        return;
    }

    int getMinimumDifference(TreeNode* root) {
        int min_diff = INT_MAX;
        vector<int> inorder;
        getInorder(root, inorder);
        for(int i = 0; i <= inorder.size() - 2; i++) min_diff = min(min_diff, abs(inorder[i + 1] - inorder[i]));
        return min_diff;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-absolute-difference-in-bst/
Author: M.R.Naganathan
*/
