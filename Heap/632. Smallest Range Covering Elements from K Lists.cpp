/*------------------------------
  Time Complexity: O(n * logk)
  Space Complexity: O(k)
---------------------------------*/

class Solution {
public:
    vector<int> smallestRange(vector<vector<int>>& nums) {
        priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> minHeap;
        int maxValue = -1e9;
        for(int i = 0; i <= nums.size() - 1; i++){
            minHeap.push({nums[i][0], {i, 0}});
            maxValue = max(nums[i][0], maxValue);
        }

        int currRange = 1e9;
        vector<int> rangePoints(2, -1);
        while(true){
            auto currPoint = minHeap.top();
            minHeap.pop();

            if(currRange > maxValue - currPoint.first){
                currRange = maxValue - currPoint.first;
                rangePoints[0] = currPoint.first;
                rangePoints[1] = maxValue;
            }

            int arrayIndex = currPoint.second.first;
            int arrayPointer = currPoint.second.second;
            if(arrayPointer + 1 >= nums[arrayIndex].size()) break;
            maxValue = max(maxValue, nums[arrayIndex][arrayPointer + 1]);
            minHeap.push({nums[arrayIndex][arrayPointer + 1], {arrayIndex, arrayPointer + 1}});
        }
        return rangePoints;
    }
};

/*
Question Link: https://leetcode.com/problems/smallest-range-covering-elements-from-k-lists/
Author: M.R.Naganathan
*/
