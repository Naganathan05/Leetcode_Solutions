/*--------------------------------
Method: Memoization
  Time Complexity: O(n)
  Space Complexity: O(n) + O(h)
----------------------------------*/

class Solution {
public:
    int Theif(TreeNode* root, unordered_map<TreeNode*, int> &dp){
        if(!root) return 0;
        if(dp.find(root) != dp.end()) return dp[root];

        int Pick = 0, noPick = 0;
        Pick += root -> val;
        if(root -> left) Pick += Theif((root -> left) -> left, dp);
        if(root -> left) Pick += Theif((root -> left) -> right, dp);
        if(root -> right) Pick += Theif((root -> right) -> left, dp);
        if(root -> right) Pick += Theif((root -> right) -> right, dp);
        noPick = Theif(root -> left, dp) + Theif(root -> right, dp);
        return dp[root] = max(Pick, noPick); 
    }

    int rob(TreeNode* root) {
        unordered_map<TreeNode*, int> dp;
        return Theif(root, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/house-robber-iii/
Author: M.R.Naganathan
*/
