/*--------------------------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------------------------*/

class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int n = intervals.size();
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        int temp = intervals[0][1];
        for(int i = 1;i<n;i++){
            if(temp >= intervals[i][0])
            {
                temp = max(intervals[i][1],temp);
                ans.back()[1] = temp;
            }
            else{
                ans.push_back(intervals[i]);
                temp = intervals[i][1];
            }
        }
        return ans;
    }
};

/*
Question Link: https://leetcode.com/problems/merge-intervals/description/
Author: M.R.Naganathan
*/
