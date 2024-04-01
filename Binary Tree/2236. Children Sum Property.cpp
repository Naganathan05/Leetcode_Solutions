/*---------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-----------------------------------------*/

bool isParentSum(Node *root){
    if(!root) return true;

    if(!root -> left && !root -> right) return true;
    int leftSum = 0, rightSum = 0;
    if(root -> left) leftSum = (root -> left) -> data;
    if(root -> right) rightSum = (root -> right) -> data;
    return (root -> data == (leftSum + rightSum)) && isParentSum(root -> left) && isParentSum(root -> right);
}

/*
Question Link: https://www.naukri.com/code360/problems/children-sum-property_8357239
Author: M.R.Naganathan
*/
