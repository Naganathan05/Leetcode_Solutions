/*--------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            long long size = q.size();
            long long temp = size;
            long long sum = 0;
            while(size){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
                sum += (currNode -> val);
                size -= 1;
            }
            ans.push_back((double) sum/temp);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/average-of-levels-in-binary-tree/?envType=study-plan-v2&envId=top-interview-150
Author: M.R.Naganathan
*/
