/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int minGroups(vector<vector<int>>& intervals) {
        int numIntervals = intervals.size();
        vector<int> startTimes;
        vector<int> endTimes;
        for(int i = 0; i <= numIntervals - 1; i++){
            startTimes.push_back(intervals[i][0]);
            endTimes.push_back(intervals[i][1] + 1);
        }

        sort(startTimes.begin(), startTimes.end());
        sort(endTimes.begin(), endTimes.end());
        int i = 0, j = 0, currGroups = 0, maxGroups = 0;
        while(i < numIntervals && j < numIntervals){
            if(startTimes[i] < endTimes[j]){
                currGroups += 1;
                i += 1;
            }
            else if(startTimes[i] > endTimes[j]){
                currGroups -= 1;
                j += 1;
            }
            else{
                i += 1;
                j += 1;
            }
            maxGroups = max(currGroups, maxGroups);
        }
        return maxGroups;
    }
};

/*
Question Link: https://leetcode.com/problems/divide-intervals-into-minimum-number-of-groups/
Author: M.R.Naganathan
*/
