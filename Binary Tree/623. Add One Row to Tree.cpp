/*---------------------------------------
Method: Breadth First Search - [BFS]
    Time Complexity: O(n)
    Space Complexity: O(n)
------------------------------------------*/

class Solution {
public:
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if(depth == 1){
            TreeNode* newNode = new TreeNode(val);
            newNode -> left = root;
            newNode -> right = NULL;
            return newNode;
        }
        int currHeight = 1;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            if(currHeight == depth - 1){
                int nodes = size;
                while(!q.empty()){
                    TreeNode* currNode = q.front();
                    q.pop();
                    TreeNode* temp = currNode -> left;
                    currNode -> left = new TreeNode(val);
                    (currNode -> left) -> left = temp;
                    temp = currNode -> right;
                    currNode -> right = new TreeNode(val);
                    (currNode -> right) -> right = temp;
                    nodes -= 1;
                }
                break;
            }
            while(size){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
                size -= 1;
            }
            currHeight += 1;
        }
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/add-one-row-to-tree/
Author: M.R.Naganathan
*/
