/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
--------------------------*/

class Solution {
public:
    void addString(TreeNode* root, string &currString, int nodeVal){
        if(nodeVal != -1e9) currString += to_string(nodeVal);
        currString += '(';
        constructString(root, currString);
        currString += ')';
        return;
    }

    void constructString(TreeNode* root, string &currString){
        if(!root) return;
        if(root -> left || root -> right) addString(root -> left, currString, root -> val);
        else currString += to_string(root -> val);

        if(root -> right) addString(root -> right, currString, -1e9);
        return;
    }

    string tree2str(TreeNode* root) {
        string currString = "";
        constructString(root, currString);
        return currString;
    }
};

/*
Question Link: https://leetcode.com/problems/construct-string-from-binary-tree/
Author: M.R.Naganathan
*/
