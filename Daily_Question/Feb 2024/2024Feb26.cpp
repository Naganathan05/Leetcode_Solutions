/*-----------------------------------------------
  Time Complexity: O(h) => h: Height of the Tree
  Space Complexity: O(h) => Recursive Stack Space
-------------------------------------------------*/

class Solution {
public:
    bool isSameTree(TreeNode* p, TreeNode* q) {
        if((p && !q) || (!p && q)) return 0;

        if(!p && !q) return 1;

        return (p -> val == q -> val) && isSameTree(p -> left, q -> left) && isSameTree(p -> right, q -> right);
    }
};

/*
Question Link: https://leetcode.com/problems/same-tree/?envType=daily-question&envId=2024-02-26
Author: M.R.Naganathan
*/
