/*-------------------------
  Time Complexity: O(n)
  Space Complexity: O(n)
---------------------------*/

func countCompleteDayPairs(hours []int) int64 {

    freqCount := make(map[int] int);

    for i := 0; i <= len(hours) - 1; i++ {
        hours[i] %= 24;
    }

    var totalPairs int64 = 0;
    for i := 0; i <= len(hours) - 1; i++ {
        neededHour := (24 - hours[i]) % 24;
        totalPairs += int64(freqCount[neededHour]);
        freqCount[hours[i]] += 1;
    }
    return totalPairs;
}

/*
Question Link: https://leetcode.com/problems/count-pairs-that-form-a-complete-day-ii/
Author: M.R.Naganathan
*/
