/*--------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
----------------------------*/

func validateCapability(houses []int, capability int, k int) bool {
    numRobbedHouses := 0;
    for i := 0; i < len(houses); i++ {
        if capability >= houses[i] {
            numRobbedHouses += 1;
            i += 1;
        }
    }
    return (numRobbedHouses >= k);
}

func minCapability(nums []int, k int) int {
    low, high := 1000000, 0;
    for _, num := range nums {
        if num > high {
            high = num;
        }

        if num < low {
            low = num;
        }
    }
  
    for low <= high {
        mid := low + (high - low) / 2;
        if validateCapability(nums, mid, k) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

/*
Question Link: https://leetcode.com/problems/house-robber-iv/
Author: M.R.Naganathan
*/
