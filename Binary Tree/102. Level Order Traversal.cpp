/*-------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------*/

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            while(size){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
                level.push_back(currNode -> val);
                size -= 1;
            }
            ans.push_back(level);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/binary-tree-level-order-traversal/
Author: M.R.Naganathan
*/
