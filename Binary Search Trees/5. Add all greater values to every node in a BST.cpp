/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
---------------------------*/

void DFS(Node* root, int &currSum){
    if(!root) return;
    DFS(root -> right, currSum);
    currSum += (root -> data);
    root -> data = currSum;
    DFS(root -> left, currSum);
    return;
}

Node* modify(Node *root)
{
    int currSum = 0;
    DFS(root, currSum);
    return root;
}

/*
Question Link: https://www.geeksforgeeks.org/problems/add-all-greater-values-to-every-node-in-a-bst/
Author: M.R.Naganathan
*/
