/*-----------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
-------------------------*/

func longestNiceSubarray(nums []int) int {
    bitMask, i, maxLen := 0, 0, 0;
    for j := 0; j <= len(nums) - 1; j++ {
        for (bitMask & nums[j]) != 0 {
            bitMask &= ^(nums[i]);
            i += 1;
        }
        bitMask |= nums[j];
        maxLen = max(maxLen, (j - i + 1));
    }
    return maxLen;
}

/*
Question Link: https://leetcode.com/problems/longest-nice-subarray/
Author: M.R.Naganathan
*/
