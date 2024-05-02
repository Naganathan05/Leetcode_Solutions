/*------------------------------------
  Time Complexity: O(h)
  Space Complexity: O(h)
---------------------------------------*/

class Solution {
  public:
    int minValue(Node* root) {
        if(!root) return 0;
        if(!root -> left && !root -> right) return root -> data;
        if(root -> left) return minValue(root -> left);
        return root -> data;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/minimum-element-in-bst/1
Author: M.R.Naganathan
*/
