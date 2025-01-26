/*---------------------------
  Time Complexity: O(n * n)
  Space Complexity: O(n)
-----------------------------*/

class Solution {
public:
    int maxSubarraySum(vector<int>& nums) {
        if (nums.empty()) return 0;
        int globalMax = nums[0];
        int currMax = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            currMax = max(nums[i], currMax + nums[i]);
            globalMax = max(globalMax, currMax);
        }
        return globalMax;
    }

    int maxFrequency(vector<int>& nums, int k) {
        int maxFreq = 0;

        for (int num : nums) maxFreq += (num == k);
        unordered_set<int> difference;
        for (int num : nums) difference.insert(k - num);

        int maxAnswer = maxFreq;
        for (int num : difference) {
            int target = 0;
            if (num == 0) target = maxFreq;
            else {
                vector<int> newArray(nums.size(), 0);
                for (int i = 0; i < nums.size(); i++) {
                    if (nums[i] == k) newArray[i] = -1;
                    else if (nums[i] == k - num) newArray[i] = 1;
                    else newArray[i] = 0;
                }

                int currLen = maxSubarraySum(newArray);
                target = currLen + maxFreq;
            }
            maxAnswer = max(maxAnswer, target);
        }
        return maxAnswer;
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-frequency-after-subarray-operation/
Author: M.R.Naganathan
*/
