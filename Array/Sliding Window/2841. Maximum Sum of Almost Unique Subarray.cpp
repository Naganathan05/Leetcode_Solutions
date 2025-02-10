/*------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
--------------------------*/

class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        unordered_map<int, int> freq;
        long long currSum = 0, maxSum = 0;

        int numUniques = 0;
        for(int j = 0; j <= k - 1; j++){
            currSum += nums[j];
            freq[nums[j]] += 1;
            numUniques += (freq[nums[j]] == 1);
        }

        if(numUniques >= m) maxSum = currSum;
        int low = 0;
        for(int i = k; i <= nums.size() - 1; i++){
            currSum += nums[i];
            currSum -= nums[low];
            freq[nums[i]] += 1;
            freq[nums[low]] -= 1;
            if(nums[i] != nums[low]){
                numUniques += (freq[nums[i]] == 1);
                numUniques -= (freq[nums[low]] == 0);
            }
            if(numUniques >= m) maxSum = max(maxSum, currSum);
            low += 1;
        }
        return maxSum;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-sum-of-almost-unique-subarray/
Author: M.R.Naganathan
*/
