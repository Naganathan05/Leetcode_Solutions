/*---------------------------
  Time Complexity: O(nlogk)
  Space Complexity: O(k)
-----------------------------*/

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<pair<int, ListNode*>, vector<pair<int, ListNode*>>, greater<pair<int, ListNode*>>> minHeap;
        for(ListNode* node : lists){
            if(node) minHeap.push({node -> val, node});
        }

        ListNode* newHead = NULL;
        ListNode* newTail = NULL;

        while(!minHeap.empty()){
            auto [currVal, currNode] = minHeap.top();
            minHeap.pop();

            if(!newHead){
                newHead = currNode;
                newTail = currNode;
            }
            else{
                newTail -> next = currNode;
                newTail = currNode;
            }
            if(currNode -> next) minHeap.push({(currNode -> next) -> val, (currNode -> next)});
        }
        return newHead;
    }
};

/*
Question Link: https://leetcode.com/problems/merge-k-sorted-lists/
Author: M.R.Naganathan
*/
