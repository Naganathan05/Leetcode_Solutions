/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long numSubarrays = 0;
        int i = 0, numPairs = 0;

        for (int j = 0; j <= nums.size() - 1; j++) {
            freq[nums[j]] += 1;
            numPairs += (freq[nums[j]] - 1);
            while (numPairs >= k) {
                numSubarrays += (nums.size() - j);
                freq[nums[i]] -= 1;
                numPairs -= (freq[nums[i]]);
                i += 1;
            }
        }
        return numSubarrays;
    }
};

/*
Question Link: https://leetcode.com/problems/count-the-number-of-good-subarrays/
Author: M.R.Naganathan
*/
