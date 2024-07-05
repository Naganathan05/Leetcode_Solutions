/*------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------------*/

class Solution {
public:
    vector<int> nodesBetweenCriticalPoints(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        vector<int> distance(2, -1);
        int firstNodeDist = -1, lastNodeDist = -1, currDist = 1;
        int minDistance = 1e9, maxDistance = 0, numCriticalPoints = 0;
        while(curr){
            if(prev && curr -> next){
                ListNode* nex = curr -> next;
                if((curr -> val > prev -> val && curr -> val > nex -> val) || (curr -> val < prev -> val && curr -> val < nex -> val)){
                    if(firstNodeDist == -1) firstNodeDist = currDist;
                    if(lastNodeDist != -1) minDistance = min(minDistance, (currDist - lastNodeDist));
                    lastNodeDist = currDist;
                    maxDistance = max(maxDistance, (currDist - firstNodeDist));
                    numCriticalPoints += 1;
                }
            }
            prev = curr;
            curr = curr -> next;
            currDist += 1;
        }
        if(numCriticalPoints <= 1) return distance;
        distance[0] = minDistance;
        distance[1] = maxDistance;
        return distance;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-minimum-and-maximum-number-of-nodes-between-critical-points/
Author: M.R.Naganathan
*/
