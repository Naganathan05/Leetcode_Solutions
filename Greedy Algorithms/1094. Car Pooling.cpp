/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    bool carPooling(vector<vector<int>>& trips, int capacity) {
        int numTrips = trips.size();
        vector<pair<int, int>> startTime;
        vector<pair<int, int>> endTime;

        for(auto trip : trips){
            startTime.push_back({trip[1], trip[0]});
            endTime.push_back({trip[2], trip[0]});
        }

        int i = 0, j = 0, currPassengers = 0;
        sort(startTime.begin(), startTime.end());
        sort(endTime.begin(), endTime.end());
        while(i < numTrips && j < numTrips){
            if(startTime[i].first < endTime[j].first){
                currPassengers += startTime[i].second;
                i += 1;
            }
            else{
                currPassengers -= endTime[j].second;
                j += 1;
            }
            if(capacity < currPassengers) return false;
        }
        return true;
    }
};

/*
Question Link: https://leetcode.com/problems/car-pooling/
Author: M.R.Naganathan
*/
