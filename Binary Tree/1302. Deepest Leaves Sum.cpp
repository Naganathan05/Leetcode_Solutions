/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------*/

class Solution {
public:
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> fifo;
        fifo.push(root);
        int currSum = root -> val;
        while(!fifo.empty()){
            int size = fifo.size();
            vector<int> currLevel;
            for(int i = 0; i < size; i++){
                TreeNode* node = fifo.front();
                fifo.pop();
                currLevel.push_back(node -> val);

                if(node -> left) fifo.push(node -> left);
                if(node -> right) fifo.push(node -> right);
            }
            currSum = 0;
            for(int i : currLevel) currSum += i;
        }
        return currSum;
    }
};

/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-----------------------------*/

class Solution {
public:
    void DFS(TreeNode* root, int currHeight, int &treeHeight, int &leavesSum){
        if(!root) return;
        if(currHeight > treeHeight){
            treeHeight = currHeight;
            leavesSum = 0;
        }

        if(currHeight == treeHeight) leavesSum += root -> val;
        DFS(root -> left, currHeight + 1, treeHeight, leavesSum);
        DFS(root -> right, currHeight + 1, treeHeight, leavesSum);
        return;
    }

    int deepestLeavesSum(TreeNode* root) {
        int treeHeight = 0, leavesSum = 0;
        DFS(root, 1, treeHeight, leavesSum);
        return leavesSum;
    }
};

/*
Question Link: https://leetcode.com/problems/deepest-leaves-sum/
Author: M.R.Naganathan
*/
