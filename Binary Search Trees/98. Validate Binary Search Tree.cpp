/*-----------------------------------------
Method: Inorder Traversal
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------------------------*/

class Solution {
public:

    void inorder(TreeNode* root, vector<int>& order){
        if(!root) return;
        inorder(root -> left, order);
        order.push_back(root -> val);
        inorder(root -> right, order);
    }

    bool isValidBST(TreeNode* root) {
        vector<int> order;
        inorder(root, order);
        for(int i = 1; i <= order.size() - 1; i++){
            if(order[i] <= order[i - 1]) return false;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/validate-binary-search-tree/
Author: M.R.Naganathan
*/
