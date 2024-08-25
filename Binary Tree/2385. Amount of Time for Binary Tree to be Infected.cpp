/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    void formGraph(TreeNode* root, unordered_map<int, vector<int>> &adjList){
        if(!root) return;
        if(root -> left){
            adjList[root -> val].push_back((root -> left) -> val);
            adjList[(root -> left) -> val].push_back(root -> val);
        }
        if(root -> right){
            adjList[root -> val].push_back((root -> right) -> val);
            adjList[(root -> right) -> val].push_back(root -> val);
        }
        formGraph(root -> left, adjList);
        formGraph(root -> right, adjList);
        return;
    }

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int, vector<int>> adjList;
        formGraph(root, adjList);

        queue<pair<int, int>> fifo;
        unordered_map<int, bool> visited;
        fifo.push({start, 0});
        visited[start] = true;
        int numMinutes = 0;

        while(!fifo.empty()){
            auto [currNode, time] = fifo.front();
            fifo.pop();

            numMinutes = max(numMinutes, time);

            for(int node : adjList[currNode]){
                if(visited.find(node) == visited.end()){
                    visited[node] = true;
                    fifo.push({node, time + 1});
                }
            }
        }
        return numMinutes;
    }
};

/*
Question Link: https://leetcode.com/problems/amount-of-time-for-binary-tree-to-be-infected/
Author: M.R.Naganathan
*/
