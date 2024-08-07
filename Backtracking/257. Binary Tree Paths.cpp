/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
---------------------------*/

class Solution {
public:
    void generate(TreeNode* root, string &currString, vector<string> &ans){
        if(!root) return;
        if(!root -> left && !root -> right){
            ans.push_back(currString + to_string(root -> val));
            return;
        }

        string temp = currString;
        currString += (to_string(root -> val) + "->");
        generate(root -> left, currString, ans);
        generate(root -> right, currString, ans);
        currString = temp;
        return;
    }

    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> ans;
        string currString;
        generate(root, currString, ans);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/binary-tree-paths/
Author: M.R.Naganathan
*/
