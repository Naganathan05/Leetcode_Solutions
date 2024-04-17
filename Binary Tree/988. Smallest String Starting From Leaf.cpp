/*--------------------------------------------
Method: Depth First Search - [DFS]
  Time Complexity: O(n)
  Space Complexity: O(h)
-----------------------------------------------*/

class Solution {
public:
    string function(TreeNode* root, string currStr) {
        currStr = char('a' + root->val) + currStr;

        if (!root->left && !root->right) return currStr;

        string left = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz", right = "zzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzz";
        if(root -> left) left = function(root->left, currStr);
        if(root -> right) right = function(root->right, currStr);

        int min_len = min(left.length(), right.length());
        for(int i = 0; i <= min_len - 1; i++){
            if(left[i] == right[i]) continue;
            if(left[i] > right[i]) return right;
            return left;
        }
        if(min_len == left.length()) return left;
        return right;
    }

    string smallestFromLeaf(TreeNode* root) {
        return function(root, "");
    }
};

/*
Question Link: https://leetcode.com/problems/smallest-string-starting-from-leaf/
Author: M.R.Naganathan
*/
