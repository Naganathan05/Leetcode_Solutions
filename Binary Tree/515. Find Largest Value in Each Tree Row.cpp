/*----------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------*/

class Solution {
public:
    vector<int> largestValues(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*> fifo;
        fifo.push(root);
        vector<int> maxValues;
        while(!fifo.empty()){
            int size = fifo.size(), maxVal = INT_MIN;
            for(int i = 0; i < size; i++){
                TreeNode* node = fifo.front();
                fifo.pop();

                if(node -> left) fifo.push(node -> left);
                if(node -> right) fifo.push(node -> right);
                maxVal = max(maxVal, node -> val);
            }
            maxValues.push_back(maxVal);
        }
        return maxValues;
    }
};

/*
Question Link: https://leetcode.com/problems/find-largest-value-in-each-tree-row/
Author: M.R.Naganathan
*/
