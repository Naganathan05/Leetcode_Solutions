/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
----------------------------*/

func validateAllocation(candies []int, maxCandies int, k int64) bool {
    var numGreaterPiles int = 0;
    for _, candy := range candies {
        numGreaterPiles += (candy / maxCandies);
    }
    return (numGreaterPiles >= int(k));
}

func maximumCandies(candies []int, k int64) int {
    low, high := 1, 0;
    for _, candy := range candies {
        if candy > high {
            high = candy;
        }
    }

    for low <= high {
        mid := low + (high - low) / 2;
        if validateAllocation(candies, mid, k) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return high;
}

/*
Question Link: https://leetcode.com/problems/maximum-candies-allocated-to-k-children/
Author: M.R.Naganathan
*/
