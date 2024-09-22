/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    long long minNumberOfSeconds(int mountainHeight, vector<int>& workerTimes) {
        int numWorkers = workerTimes.size();
        priority_queue<pair<long long, pair<int, int>>, vector<pair<long long, pair<int, int>>>, greater<pair<long long, pair<int, int>>>> minHeap;

        for (int i = 0; i < numWorkers; i++) minHeap.push({(long long)workerTimes[i], {i, 1}});
        long long maxTime = 0;

        while (mountainHeight > 0) {
            auto [currentTime, workerInfo] = minHeap.top();
            minHeap.pop();

            int workerIndex = workerInfo.first;
            int cycle = workerInfo.second;

            mountainHeight -= 1;
            maxTime = max(maxTime, currentTime);
            long long nextAvailableTime = currentTime + (long long)workerTimes[workerIndex] * (cycle + 1);
            minHeap.push({nextAvailableTime, {workerIndex, cycle + 1}});
        }
        return maxTime;
    }
};

/*
Question Link: https://leetcode.com/problems/minimum-number-of-seconds-to-make-mountain-height-zero/
Author: M.R.Naganathan
*/
