/*-----------------------------
  Time Complexity: O(n * logn)
  Space Complexity: O(n)
-------------------------------*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        sort(trips.begin(), trips.end(), 
            [&](const vector<int> &a, const vector<int> &b){
                return a[1] < b[1];
            }
        );

        int currPassengerCount = 0;
        priority_queue<pair<int, int>, 
                        vector<pair<int, int>>, 
                        greater<pair<int, int>>> minHeap;
        for(auto &trip : trips) {
            int numPassengers = trip[0];
            int from = trip[1];
            int to = trip[2];

            while(!minHeap.empty() && minHeap.top().first <= from) {
                currPassengerCount -= minHeap.top().second;
                minHeap.pop();
            }
            
            minHeap.push({to, numPassengers});
            currPassengerCount += numPassengers;
            if(currPassengerCount > capacity) return false;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/car-pooling/
Author: M.R.Naganathan
*/
