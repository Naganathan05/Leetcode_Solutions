/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    int findBottomLeftValue(TreeNode* root) {
        int height = -1, leftVal = 0;
        findVal(root, 0, height, leftVal);
        return leftVal;
    }

    void findVal(TreeNode* root, int currLevel, int &height, int &leftVal){
        if(!root) return;

        if(currLevel > height){
            height = currLevel;
            leftVal = root -> val;
        }

        findVal(root -> left, currLevel + 1, height, leftVal);
        findVal(root -> right, currLevel + 1, height, leftVal);
        return;
    }
};

/*
Question Link: https://leetcode.com/problems/find-bottom-left-tree-value/
Author: M.R.Naganathan
*/
