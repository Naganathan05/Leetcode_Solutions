/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    int numNodes(ListNode* head) {
        int count = 0;
        while (head) {
            count += 1;
            head = head->next;
        }
        return count;
    }

    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        int numNode = numNodes(head); 
        int partSize = numNode / k;
        int extraNodes = numNode % k;

        vector<ListNode*> result(k, nullptr);
        ListNode* curr = head;
        
        for (int i = 0; i < k; ++i) {
            result[i] = curr; 
            int currPartSize = partSize;
            if(extraNodes > 0){
                currPartSize += 1;
                extraNodes -= 1;
            }
            
            for (int j = 0; j < currPartSize - 1 && curr; j++) curr = curr -> next;

            if (curr) {
                ListNode* nextPart = curr -> next;
                curr -> next = NULL;
                curr = nextPart;
            }
        }
        return result;
    }
};

/*
Question Link: https://leetcode.com/problems/split-linked-list-in-parts/
Author: M.R.Naganathan
*/
