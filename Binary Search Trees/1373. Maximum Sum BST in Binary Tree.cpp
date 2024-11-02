/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
--------------------------*/

class Solution {
public:
    struct BSTInfo {
        bool isBST;
        int subtreeSum;
        int minVal;
        int maxVal;
    };

    // bool checkBST(TreeNode* root){
    //     bool isBST = true;
    //     if(root -> left) isBST &= ((root -> val) > (root -> left) -> val);
    //     if(root -> right) isBST &= ((root -> val) < (root -> right) -> val);
    //     return isBST;
    // }

    BSTInfo BSTSum(TreeNode* root, int &maxBSTSum){
        if(!root){
            maxBSTSum = max(maxBSTSum, 0);
            return BSTInfo(true, 0, 1e9, -1e9);
        }

        BSTInfo leftSubTree = BSTSum(root -> left, maxBSTSum);
        BSTInfo rightSubTree = BSTSum(root -> right, maxBSTSum);
        bool isBST = leftSubTree.isBST && rightSubTree.isBST && leftSubTree.maxVal < root -> val && rightSubTree.minVal > root -> val;
        int currSubtreeSum = (root -> val) + leftSubTree.subtreeSum + rightSubTree.subtreeSum;
        if(isBST) maxBSTSum = max(maxBSTSum, currSubtreeSum);
        int newMinVal = min({leftSubTree.minVal, rightSubTree.minVal, root -> val});
        int newMaxVal = max({leftSubTree.maxVal, rightSubTree.maxVal, root -> val});
        return BSTInfo(isBST, currSubtreeSum, newMinVal, newMaxVal);
    }

    int maxSumBST(TreeNode* root) {
        int maxBSTSum = -1e9;
        BSTSum(root, maxBSTSum);
        return maxBSTSum;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-sum-bst-in-binary-tree/
Author: M.R.Naganathan
*/
