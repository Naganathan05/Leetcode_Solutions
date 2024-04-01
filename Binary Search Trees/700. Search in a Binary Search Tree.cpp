/*-------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
---------------------------------------*/

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if(!root) return NULL;
        if(root -> val > val){
            return searchBST(root -> left, val);
        }
        else if(root -> val < val){
            return searchBST(root -> right, val);
        }
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/search-in-a-binary-search-tree/
Author: M.R.Naganathan
*/
