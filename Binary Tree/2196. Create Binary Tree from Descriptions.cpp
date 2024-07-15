/*-------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n) + O(h)
----------------------------------*/

class Solution {
public:
    void Build(unordered_map<int, vector<pair<int, int>>> &binaryTree, TreeNode* parent){
        if(binaryTree.find(parent -> val) == binaryTree.end()) return;
        for(auto itr : binaryTree[parent -> val]){
            TreeNode* node = new TreeNode(itr.first);
            if(itr.second) parent -> left = node;
            else parent -> right = node;
            Build(binaryTree, node);
        }
        return;
    }

    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int, int> parents;
        for(int i = 0; i <= descriptions.size() - 1; i++){
            parents[descriptions[i][0]] = -1;
            parents[descriptions[i][1]] = -1;
        }
        for(int i = 0; i <= descriptions.size() - 1; i++) parents[descriptions[i][1]] = descriptions[i][0];
        int rootVal;
        for(auto i : parents){
            if(i.second == -1){
                rootVal = i.first;
                break;
            }
        }

        unordered_map<int, vector<pair<int, int>>> binaryTree;
        for(int i = 0; i <= descriptions.size() - 1; i++){
            binaryTree[descriptions[i][0]].push_back({descriptions[i][1], descriptions[i][2]});
        }

        TreeNode* root = new TreeNode(rootVal);
        Build(binaryTree, root);
        return root;
    }
};

/*
Question Link: https://leetcode.com/problems/create-binary-tree-from-descriptions/
Author: M.R.Naganathan
*/
