/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, long long> freq;
        long long maxSubarraySum = LLONG_MIN;
        
        vector<long long> prefixSum(nums.size() + 1, 0);
        for(int i = 0; i < nums.size(); i++) prefixSum[i + 1] = nums[i] + prefixSum[i];
        
        for(int i = 0; i < nums.size(); i++) {
            if(freq.find(nums[i] + k) != freq.end()) {
                maxSubarraySum = max(maxSubarraySum, prefixSum[i + 1] - freq[nums[i] + k]);
            }

            if(freq.find(nums[i] - k) != freq.end()) {
                maxSubarraySum = max(maxSubarraySum, prefixSum[i + 1] - freq[nums[i] - k]);
            }

            if(freq.find(nums[i]) == freq.end()) freq[nums[i]] = prefixSum[i];
            else freq[nums[i]] = min(freq[nums[i]], prefixSum[i]);
        }
        return maxSubarraySum == LLONG_MIN ? 0 : maxSubarraySum;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-good-subarray-sum/
Author: M.R.Naganathan
*/
