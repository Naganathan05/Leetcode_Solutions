/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
---------------------------*/

func countSubarrays(nums []int, k int64) int64 {
    var currSum int64 = 0;
    var numSubarrays int64 = 0;
    i := 0;

    for j := 0; j < len(nums); j++ {
        currSum += int64(nums[j]);
        for (currSum * int64(j - i + 1)) >= k {
            currSum -= int64(nums[i]);
            i += 1;
        }
        numSubarrays += int64(j - i + 1);
    }
    return numSubarrays
}

/*
Question Link: https://leetcode.com/problems/count-subarrays-with-score-less-than-k/
Author: M.R.Naganathan
*/
