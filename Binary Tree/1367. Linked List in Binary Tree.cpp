/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    bool DFS(ListNode* head, TreeNode* root){
        if(!head) return true;
        if(!root || root -> val != head -> val) return false;
        return DFS(head -> next, root -> left) || DFS(head -> next, root -> right);
    }

    bool isSubPath(ListNode* head, TreeNode* root) {
        if(!root || !head) return false;
        if(DFS(head, root)) return true;
        return isSubPath(head, root -> left) || isSubPath(head, root -> right);
    }
};

/*
Question Link: https://leetcode.com/problems/linked-list-in-binary-tree/
Author: M.R.Naganathan
*/
