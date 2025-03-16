/*---------------------------
  Time Complexity: O(nlogn)
  Space Complexity: O(1)
-----------------------------*/

func validateRepairTime(ranks []int, cars int, maxTime int64) bool {
    numRepairableCars := 0;
    for _, rank := range ranks {
        t := int(math.Sqrt(float64(maxTime / int64(rank))))
        numRepairableCars += t;
    }
    return (numRepairableCars >= cars);
}

func repairCars(ranks []int, cars int) int64 {
    var low, high int64 = 1, int64(ranks[0]) * int64(cars) * int64(cars)
    for _, rank := range ranks {
        maxTimeForMechanic := int64(rank) * int64(cars) * int64(cars)
        if maxTimeForMechanic > high {
            high = maxTimeForMechanic
        }
    }

    for low <= high {
        var mid int64;
        mid = low + (high - low) / 2;
        if validateRepairTime(ranks, cars, mid) {
            high = mid - 1;
        } else {
            low = mid + 1;
        }
    }
    return low;
}

/*
Question Link: https://leetcode.com/problems/minimum-time-to-repair-cars/
Author: M.R.Naganathan
*/
