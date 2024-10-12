/*--------------------------
  Time Complexity: O(nlogk)
  Space Complexity: O(k)
-----------------------------*/

class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int, pair<int, int>>> maxHeap;
        for(int i = 0; i <= points.size() - 1; i++){
            int originDistance = (points[i][0] * points[i][0]) + (points[i][1] * points[i][1]);
            maxHeap.push({originDistance, {points[i][0], points[i][1]}});
            if(maxHeap.size() > k) maxHeap.pop();
        }

        vector<vector<int>> closestPoints;
        while(!maxHeap.empty()){
            auto currPoint = maxHeap.top().second;
            maxHeap.pop();
            closestPoints.push_back({currPoint.first, currPoint.second});
        }
        return closestPoints;
    }
};

/*
Question Link: https://leetcode.com/problems/k-closest-points-to-origin/
Author: M.R.Naganathan
*/
