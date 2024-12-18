/*----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-----------------------------------*/

class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        vector<int> WaitingDays(temperatures.size(), 0);
        stack<pair<int, int>> st;
        for(int i = temperatures.size() - 1; i >= 0; i--){
            int currWait = 0;
            while(!st.empty() && st.top().first <= temperatures[i]) st.pop();
            if(!st.empty()) currWait = st.top().second - i;
            st.push({temperatures[i], i});
            WaitingDays[i] = currWait;
        }
        return WaitingDays;
    }
};

/*
Question Link: https://leetcode.com/problems/daily-temperatures/
Author: M.R.Naganathan
*/
