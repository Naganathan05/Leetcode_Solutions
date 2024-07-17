/*----------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
------------------------------*/

class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        unordered_map<int, int> freq;
        long long maxSum = 0, currSum = 0;
        int currLen = 0, i = 0;
        for(int j = 0; j <= nums.size() - 1; j++){
            currLen += 1;
            currSum += (nums[j]);
            freq[nums[j]] += 1;
            while(freq[nums[j]] > 1 || currLen > k){
                currSum -= (nums[i]);
                freq[nums[i]] -= 1;
                currLen -= 1;
                i += 1;
            }
            if(currLen == k) maxSum = max(maxSum, currSum);
        }
        return maxSum;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-sum-of-distinct-subarrays-with-length-k/
Author: M.R.Naganathan
*/
