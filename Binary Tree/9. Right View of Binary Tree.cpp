/*-------------------------------------
Method: Breadth First Search - [BFS]
  Time Complexity: O(n)
  Space Complexity: O(n)
----------------------------------------*/

class Solution
{
    public:
    //Function to return list containing elements of right view of binary tree.
    vector<int> rightView(Node *root)
    {
        vector<int> ans;
        if(!root) return ans;
        queue<Node *> q;
        q.push(root);
        while(!q.empty()){
            int size = q.size();
            vector<int> ls;
            while(size){
                Node* currNode = q.front();
                q.pop();
                ls.push_back(currNode -> data);
                if(currNode -> left) q.push(currNode -> left);
                if(currNode -> right) q.push(currNode -> right);
                size -= 1;
            }
            ans.push_back(ls[ls.size() - 1]);
        }
        return ans;
    }
};

/*
Question Link: https://www.geeksforgeeks.org/problems/right-view-of-binary-tree/1
Author: M.R.Naganathan
*/
