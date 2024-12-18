/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    int numNodes(ListNode* head){
        ListNode* currNode = head;
        int nodes = 0;
        while(currNode){
            currNode = currNode -> next;
            nodes += 1;
        }
        return nodes;
    }

    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> nextLargest(numNodes(head), 0);
        stack<pair<int, int>> filo;
        int index = 0;
        ListNode* currNode = head;
        while(currNode){
            int currVal = currNode -> val;
            while(!filo.empty() && filo.top().first < currVal){
                auto [val, ind] = filo.top();
                filo.pop();
                nextLargest[ind] = currVal;
            }
            filo.push({currVal, index});
            currNode = currNode -> next;
            index += 1;
        }
        return nextLargest;
    }
};

/*
Question Link: https://leetcode.com/problems/next-greater-node-in-linked-list/
Author: M.R.Naganathan
*/
