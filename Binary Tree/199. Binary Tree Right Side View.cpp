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

/*---------------------------
Method: Depth First Search
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    void DFS(TreeNode* root, int currHeight, map<int, int> &rightView){
        if(!root) return;
        
        if(rightView.find(currHeight) == rightView.end()){
            rightView[currHeight] = root -> val;
        }
        DFS(root -> right, currHeight + 1, rightView);
        DFS(root -> left, currHeight + 1, rightView);
        return;
    }

    vector<int> rightSideView(TreeNode* root) {
        map<int, int> rightView;
        DFS(root, 0, rightView);
        vector<int> ans;
        for(auto i : rightView) ans.push_back(i.second);
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/binary-tree-right-side-view/
Author: M.R.Naganathan
*/
