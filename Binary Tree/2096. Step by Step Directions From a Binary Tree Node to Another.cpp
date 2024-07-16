/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
----------------------------*/

class Solution {
public:
    TreeNode* getLCA(TreeNode* root, int node1, int node2){
        if(!root) return NULL;
        if(root -> val == node1 || root -> val == node2) return root;

        TreeNode* leftSearch = getLCA(root -> left, node1, node2);
        TreeNode* rightSearch = getLCA(root -> right, node1, node2);
        if(leftSearch && rightSearch) return root;
        if(leftSearch) return leftSearch;
        if(rightSearch) return rightSearch;
        return NULL;
    }

    bool shortestPath(TreeNode* root, int destVal, string &currDirections){
        if(!root) return false;
        if(root -> val == destVal) return true;

        currDirections += 'L';
        if(shortestPath(root -> left, destVal, currDirections)) return true;
        currDirections.pop_back();

        currDirections += 'R';
        if(shortestPath(root -> right, destVal, currDirections)) return true;
        currDirections.pop_back();

        return false; 
    }

    string getDirections(TreeNode* root, int startValue, int destValue) {
        TreeNode* LCA = getLCA(root, startValue, destValue);

        string pathToStart;
        string pathToDest;

        shortestPath(LCA, startValue, pathToStart);
        shortestPath(LCA, destValue, pathToDest);

        string directions = "";
        for(char c : pathToStart) directions += 'U';
        directions += (pathToDest);
        return directions;
    }
};

/*
Question Link: https://leetcode.com/problems/step-by-step-directions-from-a-binary-tree-node-to-another/
Author: M.R.Naganathan
*/
