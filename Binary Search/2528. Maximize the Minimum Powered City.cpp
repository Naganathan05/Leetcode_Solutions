/*-----------------------------------------
  Time Complexity: O(nlog(sum(stations)))
  Space Complexity: O(n)
-------------------------------------------*/

class Solution {
public:
    bool isPossible(vector<int> &stations, int &maxStations, long long minPower, int &r) {
        int numStations = stations.size();
        vector<long long> lineSweep(numStations + 1, 0);

        for(int i = 0; i < numStations; i++) {
            int leftRange = max(0, i - r);
            int rightRange = min(numStations - 1, i + r);
            lineSweep[leftRange] += stations[i];
            lineSweep[rightRange + 1] -= stations[i];
        }

        long long currCityPower = 0;
        long long usedExtraStations = 0;
        for(int i = 0; i < numStations; i++) {
            currCityPower += lineSweep[i];
            if(currCityPower >= minPower) continue;

            int rightRange = min(numStations - 1, i + (2 * r));
            lineSweep[i] += (minPower - currCityPower);
            lineSweep[rightRange + 1] -= (minPower - currCityPower);
            usedExtraStations += (minPower - currCityPower);
            currCityPower = minPower;
            if(usedExtraStations > maxStations) return false;
        }
        return true;
    }

    long long maxPower(vector<int>& stations, int r, int k) {
        int numStations = stations.size();
        vector<long long> lineSweep(numStations + 1, 0);

        for(int i = 0; i < numStations; i++) {
            int leftRange = max(0, i - r);
            int rightRange = min(numStations - 1, i + r);
            lineSweep[leftRange] += stations[i];
            lineSweep[rightRange + 1] -= stations[i];
        }

        for(int i = 1; i <= numStations; i++) lineSweep[i] += lineSweep[i - 1];

        long long low = *min_element(lineSweep.begin(), lineSweep.end());
        long long high = *max_element(lineSweep.begin(), lineSweep.end()) + k;

        while (low <= high) {
            long long mid = low + (high - low) / 2;
            if (isPossible(stations, k, mid, r)) low = mid + 1;
            else high = mid - 1;
        }
        return high;
    }
};

/*
Question Link: https://leetcode.com/problems/maximize-the-minimum-powered-city/
Author: M.R.Naganathan
*/
