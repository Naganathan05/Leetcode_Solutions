/*----------------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
------------------------------------*/

class Solution {
public:
    long long countSubarrays(vector<int>& nums, int k) {
        int max_ele = INT_MIN;
        for (int i : nums) max_ele = max(max_ele, i);

        long long ans = 0, numSub = 0;
        int i = 0;
        for (int j = 0; j < nums.size(); j++) {
            if (nums[j] == max_ele) ans++;
            while (ans >= k) {
                if (nums[i] == max_ele) ans--;
                i++;
            }
            numSub += (j - i + 1);
        }

        int n = nums.size();
        long long totalSubarrays = (long long)n * (n + 1) / 2;
        return totalSubarrays - numSub;
    }
};

/*
Question Link: https://leetcode.com/problems/count-subarrays-where-max-element-appears-at-least-k-times/
Author: M.R.Naganathan
*/
