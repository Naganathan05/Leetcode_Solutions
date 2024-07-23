/*-----------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-------------------------------*/

class Solution {
public:
    int Smallest(TreeNode* root, int &k){
        if(!root) return -1;
        int left = Smallest(root -> left, k);
        k -= 1;
        if(k == 0) return root -> val;
        int right = Smallest(root -> right, k);
        if(left != -1) return left;
        if(right != -1) return right;
        return -1;
    }

    int kthSmallest(TreeNode* root, int k) {
        return Smallest(root, k);
    }
};

/*
Question Link: https://leetcode.com/problems/kth-smallest-element-in-a-bst/
Author: M.R.Naganathan
*/
