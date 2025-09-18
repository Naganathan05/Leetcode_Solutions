/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------*/

class Solution {
public:
    int computeMaxSum(vector<int> &nums, int firstLen, int secondLen) {
        int maxFirstArraySum = 0, secondArraySum = 0;

        for(int i = 0; i < firstLen; i++) maxFirstArraySum += nums[i];
        for(int i = firstLen; i < firstLen + secondLen; i++) secondArraySum += nums[i];
        int maxSum = maxFirstArraySum + secondArraySum;

        int currLeftSum = maxFirstArraySum;
        for(int j = firstLen, i = 0; (j + secondLen) < nums.size(); j++, i++) {
            currLeftSum -= nums[i];
            currLeftSum += nums[j];
            maxFirstArraySum = max(maxFirstArraySum, currLeftSum);
            secondArraySum -= nums[j];
            secondArraySum += nums[j + secondLen];
            maxSum = max(maxSum, (maxFirstArraySum + secondArraySum));
        }
        return maxSum;
    }

    int maxSumTwoNoOverlap(vector<int>& nums, int firstLen, int secondLen) {
        return max(computeMaxSum(nums, firstLen, secondLen), computeMaxSum(nums, secondLen, firstLen));
    }
};

/*
Question Link: https://leetcode.com/problems/maximum-sum-of-two-non-overlapping-subarrays/
Author: M.R.Naganathan
*/
