/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int getMinSwaps(vector<int> levelOrder){
        vector<int> sortedLevel = levelOrder;
        sort(sortedLevel.begin(), sortedLevel.end());
        unordered_map<int, int> sortedLevelMapping;
        for(int i = 0; i < sortedLevel.size(); i++) sortedLevelMapping[sortedLevel[i]] = i;

        int minSwaps = 0;
        for(int i = 0; i < levelOrder.size(); ){
            int targetInd = sortedLevelMapping[levelOrder[i]];
            if(targetInd == i) i += 1;
            else {
                minSwaps += 1;
                swap(levelOrder[targetInd], levelOrder[i]);
            }
        }
        return minSwaps;
    }

    int minimumOperations(TreeNode* root) {
        int totalSwaps = 0;
        queue<TreeNode*> fifo;
        fifo.push(root);

        while(!fifo.empty()) {
            int size = fifo.size();
            vector<int> levelElements;
            for(int i = 0; i < size; i++){
                TreeNode* currNode = fifo.front();
                fifo.pop();

                if(currNode -> left) fifo.push(currNode -> left);
                if(currNode -> right) fifo.push(currNode -> right);
                levelElements.push_back(currNode -> val);
            }
            totalSwaps += getMinSwaps(levelElements);
        }
        return totalSwaps;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-operations-to-sort-a-binary-tree-by-level/description/
Author: M.R.Naganathan
*/
