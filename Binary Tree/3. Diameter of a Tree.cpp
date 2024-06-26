/*--------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-----------------------------------*/

class Solution {
  public:
    int getDiameter(Node* root, int &Diameter){
        if(!root) return 0;
        int leftHeight = getDiameter(root -> left, Diameter);
        int rightHeight = getDiameter(root -> right, Diameter);
        Diameter = max(Diameter, (leftHeight + rightHeight + 1));
        return 1 + max(leftHeight, rightHeight);
    }
    int diameter(Node* root) {
        int Diameter;
        getDiameter(root, Diameter);
        return Diameter;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/diameter-of-binary-tree/1
Author: M.R.Naganathan
*/
