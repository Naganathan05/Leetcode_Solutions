/*-----------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
-------------------------------------------------*/

class Solution{
  public:
    bool checkLevel(Node *root, int height, int currheight){
        if(root -> left == NULL && root -> right == NULL){
            return (currheight == height - 1);
        }
        
        if(root -> left == NULL) return checkLevel(root -> right, height, currheight + 1);
        if(root -> right == NULL) return checkLevel(root -> left, height, currheight + 1);
        
        currheight += 1;
        return checkLevel(root -> left, height, currheight) && checkLevel(root -> right, height, currheight);
    }
    
    bool check(Node *root)
    {
        int height = getHeight(root);
        return checkLevel(root, height, 0);
    }
    
    int getHeight(Node *root){
        if(!root) return 0;
        
        return 1 + max(getHeight(root -> left), getHeight(root -> right));
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/leaf-at-same-level/1
Author: M.R.Naganathan
*/
