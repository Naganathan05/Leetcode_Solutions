/*---------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------*/

void inorder(TreeNode<int>* root, vector<int> &arr){
    if(!root) return;
    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
    return;
}

int KthLargestNumber(TreeNode<int>* root, int k) 
{
    vector<int> arr;
    inorder(root, arr);
    if(arr.size() < k) return -1;
    return arr[arr.size() - k];
}

/*
Question Link: https://www.naukri.com/code360/problems/k-th-largest-number_920438
Author: M.R.Naganathan
*/
