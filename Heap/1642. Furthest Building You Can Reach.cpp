/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        priority_queue<int, vector<int>, greater<int>> minHeap;
        for(int i = 0; i < heights.size() - 1; i++) {
            int jumpHeight = heights[i + 1] - heights[i];
            if(jumpHeight <= 0) continue;
            minHeap.push(jumpHeight);
            if(ladders > 0) ladders -= 1;
            else {
                if(bricks < minHeap.top()) return i;
                bricks -= minHeap.top();
                minHeap.pop();
            }
        }
        return heights.size() - 1;
    }
};

/*
Question Link: https://leetcode.com/problems/furthest-building-you-can-reach/
Author: M.R.Naganathan
*/
