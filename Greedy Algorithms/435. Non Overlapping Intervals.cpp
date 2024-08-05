/*------------------------------
Method: Greedy Algorithms
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
---------------------------------*/

class Solution {
public:
    static bool comparator(const vector<int>& a, const vector<int>& b) {
        return a[1] < b[1];
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), comparator);
        int nonOverlappingCount = 1, lastFinishedTime = intervals[0][1], n = intervals.size();
        for(int i = 1; i <= n - 1; i++){
            if(lastFinishedTime <= intervals[i][0]){
                nonOverlappingCount += 1;
                lastFinishedTime = intervals[i][1];
            }
        }
        return n - nonOverlappingCount;
    }
};

/*-------------------------------------
Method: Dynamic Programming
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
---------------------------------------*/

class Solution {
public:
    int Overlap(vector<vector<int>> &intervals, int i, int &n, vector<int> &startTime, vector<int> &dp) {
        if (i >= n) return 0;
        if (dp[i] != -1) return dp[i];

        int index = lower_bound(startTime.begin(), startTime.end(), intervals[i][1]) - startTime.begin();
        int Pick = 1 + Overlap(intervals, index, n, startTime, dp);
        int noPick = Overlap(intervals, i + 1, n, startTime, dp);
        return dp[i] = max(Pick, noPick);
    }

    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        int n = intervals.size();
        if (n == 0) return 0;

        sort(intervals.begin(), intervals.end());

        vector<int> startTime;
        for (int i = 0; i < n; i++) startTime.push_back(intervals[i][0]);

        vector<int> dp(n, -1);
        int nonOverlappingCount = Overlap(intervals, 0, n, startTime, dp);
        return n - nonOverlappingCount;
    }
};

/*
Question Link: https://leetcode.com/problems/non-overlapping-intervals/description/
Author: M.R.Naganathan
*/
