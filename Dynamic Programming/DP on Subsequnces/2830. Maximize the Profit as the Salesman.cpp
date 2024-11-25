/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int lowerBound(vector<vector<int>> &offers, int low, int currPos) {
        int high = offers.size() - 1, ans = offers.size();
        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (offers[mid][0] > currPos) {
                ans = mid;
                high = mid - 1;
            }
            else low = mid + 1;
        }
        return ans;
    }

    int SellHouse(vector<vector<int>> &offers, int i, vector<int> &dp) {
        if (i == offers.size()) return 0;
        if (dp[i] != -1) return dp[i];

        int Pick = 0, noPick = 0;
        int ind = lowerBound(offers, i + 1, offers[i][1]);
        Pick = offers[i][2] + SellHouse(offers, ind, dp);
        noPick = SellHouse(offers, i + 1, dp);
        return dp[i] = max(Pick, noPick);
    }

    int maximizeTheProfit(int n, vector<vector<int>> &offers) {
        sort(offers.begin(), offers.end(), [](vector<int> &a, vector<int> &b) {
            return a[0] < b[0];
        });
        vector<int> dp(offers.size(), -1);
        return SellHouse(offers, 0, dp);
    }
};

/*
Question Link: https://leetcode.com/problems/maximize-the-profit-as-the-salesman/
Author: M.R.Naganathan
*/
