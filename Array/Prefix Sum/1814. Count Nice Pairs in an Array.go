/*--------------------------
  Time Complexity: O(n)
  Space Complexity: O(1)
----------------------------*/

func reverseNumber(num int) int {
    reversedNum := 0
    isNegative := num < 0
    if isNegative {
        num = -num
    }

    for num > 0 {
        reversedNum = (reversedNum * 10) + (num % 10)
        num /= 10
    }

    if isNegative {
        reversedNum = -reversedNum
    }
    return reversedNum
}

func countNicePairs(nums []int) int {
    numPairs := 0;
    var mod int = 1e9 + 7;
    countMap := make(map[int] int)

    for _, num := range nums {
        searchValue := num - reverseNumber(num)
        freq := countMap[searchValue];
        numPairs = (numPairs + freq) % mod;
        countMap[searchValue] += 1;
    }
    return numPairs
}

/*
Question Link: https://leetcode.com/problems/count-nice-pairs-in-an-array/
Author: M.R.Naganathan
*/
