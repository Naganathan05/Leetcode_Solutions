/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
--------------------------*/

class Solution {
public:
    int DFS(TreeNode* root, bool isEvenGP){
        if(!root) return 0;

        int totalSum = 0;

        if(isEvenGP){
            if(root -> left) totalSum += (root -> left) -> val;
            if(root -> right) totalSum += (root -> right) -> val;
        }

        isEvenGP = ((root -> val) % 2 == 0);
        totalSum += DFS(root -> left, isEvenGP);
        totalSum += DFS(root -> right, isEvenGP);
        return totalSum;
    }

    int sumEvenGrandparent(TreeNode* root) {
        return DFS(root, false);
    }
};

/*
Question Link: https://leetcode.com/problems/sum-of-nodes-with-even-valued-grandparent/
Author: M.R.Naganathan
*/
