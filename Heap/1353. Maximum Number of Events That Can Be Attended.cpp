/*----------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    int maxEvents(vector<vector<int>>& events) {
        // Idea is to Sort the events based on their startTime.
        // Then Simulate the days of meeting one by one.
        sort(events.begin(), events.end());

        int currDay = 1, numEvents = 0, ind = 0;
        priority_queue<int, vector<int>, greater<int>> minHeap;
        while(!minHeap.empty() || ind < events.size()) {

            // On day each push endTimes of the events that start at the current day.
            while(ind < events.size() && events[ind][0] == currDay) {
                minHeap.push(events[ind][1]);
                ind += 1;
            }

            // Eliminate all the events whose endTime has passed the current day.
            while(!minHeap.empty() && minHeap.top() < currDay) minHeap.pop();

            // Then greedily pick the event which has the shortest endTime (Using minHeap).
            if(!minHeap.empty()) {
                numEvents += 1;
                minHeap.pop();
            }

            // Assume that event would be attended at that day and move to the next Day.
            currDay += 1;
        }
        return numEvents;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended/
Author: M.R.Naganathan
*/
