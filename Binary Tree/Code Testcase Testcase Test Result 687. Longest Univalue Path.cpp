/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
--------------------------*/

class Solution {
public:
    pair<int, int> longestPath(TreeNode* root, int &maxLength) {
        if (!root) return {-1, -1};
        
        pair<int, int> leftPath = {-1, -1}, rightPath = {-1, -1};
        if (root -> left) leftPath = longestPath(root -> left, maxLength);
        if (root -> right) rightPath = longestPath(root -> right, maxLength);

        int leftMax = 0, rightMax = 0;
        if (leftPath.first == root->val) leftMax = leftPath.second + 1;
        if (rightPath.first == root->val) rightMax = rightPath.second + 1;

        maxLength = max(maxLength, leftMax + rightMax);
        return {root->val, max(leftMax, rightMax)};
    }

    int longestUnivaluePath(TreeNode* root) {
        if (!root) return 0;
        int maxLength = 0;
        longestPath(root, maxLength);
        return maxLength;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-univalue-path/
Author: M.R.Naganathan
*/
