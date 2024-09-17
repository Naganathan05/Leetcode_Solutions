/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-------------------------*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root) return NULL;
        if(root -> left) (root -> left) -> next = root -> right;
        if(root -> right && root -> next) (root -> right) -> next = (root -> next) -> left;
        connect(root -> left);
        connect(root -> right);
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/populating-next-right-pointers-in-each-node/
Author: M.R.Naganathan
*/
