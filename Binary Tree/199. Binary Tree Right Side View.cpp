/*--------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------*/

class Solution {
public:
    vector<int> rightSideView(TreeNode* root) {
        vector<int> ans;
        if(!root) return ans;
      
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            while(size){
                TreeNode* currNode = q.front();
                q.pop();
                if(size == 1) ans.push_back(currNode -> val);
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
                size -= 1;
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/binary-tree-right-side-view/
Author: M.R.Naganathan
*/
