/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    TreeNode* constructTree(unordered_map<int, ListNode*> &listMapping, int low, int high){
        if(low > high) return NULL;

        int mid = low + (high - low) / 2;
        ListNode* midNode = listMapping[mid];
        TreeNode* newNode = new TreeNode(midNode -> val);

        newNode -> left = constructTree(listMapping, low, mid - 1);
        newNode -> right = constructTree(listMapping, mid + 1, high);
        return newNode;
    }

    TreeNode* sortedListToBST(ListNode* head) {
        unordered_map<int, ListNode*> listMapping;
        ListNode* currNode = head;
        int index = 0;

        while(currNode){
            listMapping[index] = currNode;
            currNode = currNode -> next;
            index += 1;
        }
        return constructTree(listMapping, 0, index - 1);
    }
};

/*
Question Link: https://leetcode.com/problems/convert-sorted-list-to-binary-search-tree/
Author: M.R.Naganathan
*/
