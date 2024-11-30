/*-------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------------------*/

void inorder(BinaryTreeNode<int>* root, vector<int>& arr){
    if(!root) return;
    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
    return;
}

bool twoSumInBST(BinaryTreeNode<int>* root, int target) {
	vector<int> arr;
    inorder(root, arr);
    int i = 0, j = arr.size() - 1;
    while(i < j){
        if(arr[i] + arr[j] < target) i += 1;
        else if(arr[i] + arr[j] > target) j -= 1;
        else return true;
    }
    return false;
}

/*-------------------------------
   Time Complexity: O(nlogn)
   Space Complexity: O(h)
---------------------------------*/

class Solution {
public:
    bool binarySearch(TreeNode* root, int &target, TreeNode* node){
        if(!root) return false;
        if(root -> val == target && root != node) return true;
        if(root -> val > target) return binarySearch(root -> left, target, node);
        return binarySearch(root -> right, target, node);
    }

    bool DFS(TreeNode* currNode, TreeNode* root, int k){
        if(!currNode) return false;
        int target = k - (currNode -> val);
        if(binarySearch(root, target, currNode) || binarySearch(root, target, currNode)) return true;
        return DFS(currNode -> left, root, k) || DFS(currNode -> right, root, k);
    }

    bool findTarget(TreeNode* root, int k) {
        return DFS(root, root, k);
    }
};

/*
Question Link [Coding Ninja]: https://www.naukri.com/code360/problems/pair-sum_4444818
Question Link [Leetcode]: https://leetcode.com/problems/two-sum-iv-input-is-a-bst/
Author: M.R.Naganathan
*/
