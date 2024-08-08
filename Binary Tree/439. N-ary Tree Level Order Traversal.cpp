/*----------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        if(!root) return {};
        vector<vector<int>> ans;
        queue<Node*> fifo;
        fifo.push(root);
        ans.push_back({root -> val});
        while(!fifo.empty()){
            int currSize = fifo.size();
            vector<int> currLevel;
            for(int i = 0; i < currSize; i++){
                Node* node = fifo.front();
                fifo.pop();

                for(Node* neighbour : node -> children){
                    currLevel.push_back(neighbour -> val);
                    fifo.push(neighbour);
                }
            }
            if(!currLevel.empty()) ans.push_back(currLevel);
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/n-ary-tree-level-order-traversal/
Author: M.R.Naganathan
*/
