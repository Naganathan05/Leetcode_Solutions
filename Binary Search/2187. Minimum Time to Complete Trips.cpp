/*-----------------------------------------------------
  Time Complexity: O(n * log(min(times) * totalTrips))
  Space Complexity: O(1)
-------------------------------------------------------*/

class Solution {
public:
    bool validateTime(vector<int> &times, long long &minTime, int &targetTrips) {
        long long numTrips = 0;
        for(auto &time : times) numTrips += (minTime / time);
        return numTrips >= targetTrips;
    }

    long long minimumTime(vector<int>& time, int totalTrips) {
        long long low = 1;
        long long high = 1LL * (*min_element(time.begin(), time.end())) * totalTrips;

        while(low <= high) {
            long long mid = low + (high - low) / 2;
            if(validateTime(time, mid, totalTrips)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-time-to-complete-trips/
Author: M.R.Naganathan
*/
