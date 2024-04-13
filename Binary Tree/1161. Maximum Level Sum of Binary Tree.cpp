/*-------------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------------*/

class Solution {
public:
    int maxLevelSum(TreeNode* root) {
        int maxsumlvl = 0, maxSum = INT_MIN, cnt = 1;
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            int sum = 0;
            while(size){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
                sum += currNode -> val;
                size -= 1;
            }
            if(maxSum < sum){
                maxSum = sum;
                maxsumlvl = cnt;
            }
            cnt += 1;
        }
        return maxsumlvl;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-level-sum-of-a-binary-tree/
Author: M.R.Naganathan
*/
