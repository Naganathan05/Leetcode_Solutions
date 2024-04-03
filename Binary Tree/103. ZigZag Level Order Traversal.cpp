/*---------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------------------*/

class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if(!root) return ans;
        queue<TreeNode*> q;
        bool flag = false;
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
            if(flag) reverse(level.begin(), level.end());
            flag = !flag;
            ans.push_back(level);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/binary-tree-zigzag-level-order-traversal/
Author: M.R.Naganathan
*/
