/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
--------------------------*/

class Solution {
public:
    int mod = 1e9 + 7;
    int numOfSubarrays(vector<int>& nums) {
        int oddSumCount = 0, evenSumCount = 1;
        int currSum = 0, oddSumSubarrayCount = 0;

        for(int i : nums) {
            currSum += i;

            // Odd Sum - Even Sum = Odd Sum
            if(currSum % 2) {
                oddSumSubarrayCount = (oddSumSubarrayCount + evenSumCount) % mod;
                oddSumCount += 1;
            }
            // Even Sum - Odd Sum = Odd Sum
            else {
                oddSumSubarrayCount = (oddSumSubarrayCount + oddSumCount) % mod;
                evenSumCount += 1;
            }
        }
        return oddSumSubarrayCount;
    }
};

/*
Question Link: https://leetcode.com/problems/number-of-sub-arrays-with-odd-sum/
Author: M.R.Naganathan
*/
