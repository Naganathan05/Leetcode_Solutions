/*---------------------------------
  Time Complexity: O(n * log(max))
  Space Complexity: O(1)
------------------------------------*/

class Solution {
public:
    bool checkThreshold(vector<int> &nums, int divisor, int threshold) {
        int totalSum = 0;
        for(int i : nums) totalSum += ceil((double)i / divisor);
        return totalSum <= threshold;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {
        int low = 1, high = 0;
        for(int i : nums) high = max(high, i);

        while(low <= high) {
            int mid = low + (high - low) / 2;
            if(checkThreshold(nums, mid, threshold)) high = mid - 1;
            else low = mid + 1;
        }
        return low;
    }
};

/*
Question Link: https://leetcode.com/problems/find-the-smallest-divisor-given-a-threshold/
Author: M.R.Naganathan
*/
