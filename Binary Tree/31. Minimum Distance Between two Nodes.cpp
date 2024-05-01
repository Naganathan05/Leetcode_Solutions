/*--------------------------------------------
  Time Complexity: O(n)
  Space Complexity: O(h)
------------------------------------------------*/

class Solution{
    public:
    /* Should return minimum distance between a and b
    in a tree with given root*/
    int findDist(Node* root, int a, int b) {
        Node* LCA = findLCA(root, a, b);
        int leftdist = 0, rightdist = 0;
        getDist(LCA, a, leftdist);
        getDist(LCA, b, rightdist);
        return leftdist + rightdist;
    }
    
    Node* findLCA(Node* root, int a, int b){
        if(!root) return NULL;
        if(root -> data == a || root -> data == b) return root;
        Node* leftSearch = findLCA(root -> left, a, b);
        Node* rightSearch = findLCA(root -> right, a, b);
        if(leftSearch && rightSearch) return root;
        if(leftSearch) return leftSearch;
        if(rightSearch) return rightSearch;
        return NULL;
    }
    
    bool getDist(Node* root, int x, int& dist){
        if(!root) return false;
        if(root -> data == x) return true;
        
        dist += 1;
        if(getDist(root -> left, x, dist) || getDist(root -> right, x, dist)) return true;
        dist -= 1;
        return false;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/min-distance-between-two-given-nodes-of-a-binary-tree/1
Author: M.R.Naganathan
*/
