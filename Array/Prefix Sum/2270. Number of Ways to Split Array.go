/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------*/

func waysToSplitArray(nums []int) int {
    totalSum := 0;
    for _, num := range nums {
        totalSum += num;
    }

    currSum := 0;
    var numSplits int = 0;
    for i := 0; i <= len(nums) - 2; i++ {
        currSum += nums[i];
        if totalSum - currSum <= currSum {
            numSplits += 1;
        }
    }
    return numSplits;
}

/*
Question Link: https://leetcode.com/problems/number-of-ways-to-split-array/
Author: M.R.Naganathan
*/
