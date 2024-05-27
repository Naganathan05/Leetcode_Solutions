/*---------------------------------------
  Time Complexity: O(max(m, n))
  Space Complexity: O(max(m, n))
-----------------------------------------*/

void inorder(TreeNode *root, vector<int>& arr){
    if(!root) return;
    inorder(root -> left, arr);
    arr.push_back(root -> data);
    inorder(root -> right, arr);
    return;
}

vector<int> mergeBST(TreeNode *root1, TreeNode *root2)
{
    vector<int> Tree1, Tree2, ans;
    inorder(root1, Tree1);
    inorder(root2, Tree2);

    int i = 0, j = 0;
    while(i <= Tree1.size() - 1 && j <= Tree2.size() - 1){
        if(Tree1[i] >= Tree2[j]){
            ans.push_back(Tree2[j]);
            j += 1;
        }
        else{
            ans.push_back(Tree1[i]);
            i += 1;
        }
    }

    while(i <= Tree1.size() - 1){
        ans.push_back(Tree1[i]);
        i += 1;
    }

    while(j <= Tree2.size() - 1){
        ans.push_back(Tree2[j]);
        j += 1;
    }
    return ans;
}

/*
Question Link: https://www.naukri.com/code360/problems/h_920474
Author: M.R.Naganathan
*/
