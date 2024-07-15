/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------*/

class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        vector<vector<int>> ans;
        int i = 0, n = intervals.size();
        while(i < n && intervals[i][1] < newInterval[0]){
            ans.push_back(intervals[i]);
            i += 1;
        }

        while(i < n && newInterval[1] >= intervals[i][0]){
            newInterval = {min(newInterval[0], intervals[i][0]), max(newInterval[1], intervals[i][1])};
            i += 1;
        }
        ans.push_back(newInterval);

        while(i < n){
            ans.push_back(intervals[i]);
            i += 1;
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/insert-interval/
Author: M.R.Naganathan
*/
