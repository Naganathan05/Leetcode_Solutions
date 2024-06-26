/*------------------------------------
Method - Breadth First Search - [BFS]
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------*/

class Solution {
public:
    void reverse(vector<TreeNode *> &currLevel){
        int i = 0, j = currLevel.size() - 1;
        while(i <= j){
            swap(currLevel[i] -> val, currLevel[j] -> val);
            i += 1;
            j -= 1;
        }
        return;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        bool isOdd = false;
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<TreeNode*> currLevel; 
            for(int i = 0; i <= size - 1; i++){
                TreeNode* currNode = q.front();
                q.pop();
                currLevel.push_back(currNode);
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
            }
            if(isOdd) reverse(currLevel);
            isOdd = !isOdd;
        }
        return root;
    }
};

/*---------------------------------------
Method: Depth First Search - [DFS]
    Time Complexity: O(n)
    Space Complexity: O(h)
------------------------------------------*/

class Solution {
public:
    void DFS(TreeNode* node1, TreeNode* node2, int currLevel){
        if(!node1 || !node2) return;
        if(currLevel % 2 == 1) swap(node1 -> val, node2 -> val);

        DFS(node1 -> left, node2 -> right, currLevel + 1);
        DFS(node1 -> right, node2 -> left, currLevel + 1);
        return;
    }

    TreeNode* reverseOddLevels(TreeNode* root) {
        if(!root) return root;
        DFS(root -> left, root -> right, 1);
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/reverse-odd-levels-of-binary-tree/
Author: M.R.Nagnathan
*/
