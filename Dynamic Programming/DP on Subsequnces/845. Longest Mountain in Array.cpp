/*-----------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
-------------------------------*/

class Solution {
public:
    int longestMountain(vector<int>& arr) {
        int n = arr.size();
        if (n < 3) return 0;

        vector<int> increasingSub(n, 0), decreasingSub(n, 0);

        for (int i = 1; i < n; i++) {
            if (arr[i] > arr[i - 1]) increasingSub[i] = increasingSub[i - 1] + 1;
        }

        for (int i = n - 2; i >= 0; i--) {
            if (arr[i] > arr[i + 1]) decreasingSub[i] = decreasingSub[i + 1] + 1;
        }

        int mountainLen = 0;
        for (int i = 1; i < n - 1; i++) {
            if (increasingSub[i] > 0 && decreasingSub[i] > 0) mountainLen = max(mountainLen, increasingSub[i] + decreasingSub[i] + 1);
        }

        return mountainLen;
    }
};

/*
Question Link: https://leetcode.com/problems/longest-mountain-in-array/
Author: M.R.Naganathan
*/
