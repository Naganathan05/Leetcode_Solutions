/*--------------------------
  Time Complexity: O(n * k)
  Space Complexity: O(n * k)
-----------------------------*/

class Solution {
public:
    // CHAT GPT Code :(
    // Memoization + Binary Search -> TLE
    int maxValue(vector<vector<int>>& events, int k) {
        int n = events.size();
        sort(events.begin(), events.end());

        vector<int> nextEvent(n, n);
        for (int i = 0; i < n; i++) {
            auto it = lower_bound(events.begin() + i + 1, events.end(), vector<int>{events[i][1] + 1, 0, 0}, [](const vector<int> &a, const vector<int> &b) {
                return a[0] < b[0];
            });
            nextEvent[i] = it - events.begin();
        }

        vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
        for (int i = n - 1; i >= 0; i--) {
            for (int j = 1; j <= k; j++) {
                int Pick = events[i][2] + dp[nextEvent[i]][j - 1];
                int noPick = dp[i + 1][j];
                dp[i][j] = max(Pick, noPick);
            }
        }
        return dp[0][k];
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-number-of-events-that-can-be-attended-ii/
Author: M.R.Naganathan
*/
