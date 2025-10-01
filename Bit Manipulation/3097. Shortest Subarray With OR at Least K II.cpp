/*----------------------------
  Time Complexity: O(n * 32)
  Space Complexity: O(32)
------------------------------*/

class Solution {
public:
    void addToWindow(vector<int> &bitFrequency, int num) {
        for (int i = 0; i < 32; i++) {
            bitFrequency[i] += (num & 1);
            num >>= 1;
        }
    }

    void removeFromWindow(vector<int> &bitFrequency, int num) {
        for (int i = 0; i < 32; i++) {
            bitFrequency[i] -= (num & 1);
            num >>= 1;
        }
    }

    int getWindowOrValue(vector<int> &bitFrequency) {
        int orValue = 0;
        for (int i = 0; i < 32; i++) {
            if (bitFrequency[i] > 0) orValue |= (1 << i);
        }
        return orValue;
    }

    int minimumSubarrayLength(vector<int>& nums, int k) {
        vector<int> bitFrequency(32, 0);
        int minLen = INT_MAX;

        for (int j = 0, i = 0; j < nums.size(); j++) {
            addToWindow(bitFrequency, nums[j]);
            while (i <= j && getWindowOrValue(bitFrequency) >= k) {
                minLen = min(minLen, (j - i + 1));
                removeFromWindow(bitFrequency, nums[i]);
                i += 1;
            }
        }
        return minLen == INT_MAX ? -1 : minLen;
    }
};

/*
Question Link: https://leetcode.com/problems/shortest-subarray-with-or-at-least-k-ii/
Author: M.R.Naganathan
*/
