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

/*
Question Link: https://www.naukri.com/code360/problems/pair-sum_4444818
Author: M.R.Naganathan
*/
